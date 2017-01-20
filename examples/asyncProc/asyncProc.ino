// Это для << в сторону Serial :)
template<class T> inline Print &operator <<(Print &obj, T arg) {
  obj.print(arg);
  return obj;
}
#define endl "\n"

// Собственно прога

// Без этого никак.
#include "SmartDelay.h"

// Порождаем свой класс от SmartDelay.
class MyProc : public SmartDelay {
  private:
    // Это переменные наши, счётчики, строчки, настройки итп.
    char *name;
    int counter;
  public:
    // Конструктор с инициализацией чего там надо.
    MyProc(const char *p, unsigned long c) {
      name = p;
      counter = 0;
      Set(c); // Временной интервал выполнения можно задать так. Это метод из SmartDelay.
    }
    // Это наш процесс! Он будет выполняться раз в "c" микросекунд (см конструктор). 
    void Process() {
      counter++;
      Serial << "Process " << name << " counter " << counter << endl;
    }
};

// Порождаем чуть другой процесс, это другой объект с другими свойствами.
class MyProcUn : public SmartDelay {
  private:
    // Локальные переменные класса другие.
    int counter;
  public:
    // Для простоты конструктор передаёт родителю параметр -- интервал запуска.
    MyProcUn(unsigned long c) : SmartDelay(c) {};
    // Собственно процесс. Можно писать своё что-то.
    void Process() {
      counter++;
      Serial << "Process " << "Noname" << " counter " << counter << endl;
    }
};

// Объявляем и инициализируем процессы.
MyProc p1("proc0", 1000000UL), p2("zopa1", 2000000UL);
MyProc p3("yuxa2", 3000000UL);
MyProcUn p4(1000000UL);

// Магия здесь. Это не функция, а страшный макрос, 
// который порождает экземпляр класса coopTask с именем "c" и 
// передаёт ему статический массив указателей на процессы.
COOPTASK(c, &p1, &p2, &p3, &p4);

void setup () {
  Serial.begin(115200);
  Serial.println("Ready");
}

void loop() {
  c.run(); // Это всё, что нам надо в этой функции. Все процессы будут выполняться не особо мешая друг другу.
}
