
template<class T> inline Print &operator <<(Print &obj, T arg) {
  obj.print(arg);
  return obj;
}
#define endl "\n"

#include "SmartDelay.h"

class MyProc : public SmartDelay {
  private:
    char *name;
    int counter;
  public:
    MyProc(const char *p, unsigned long c) {
      name = p;
      counter = 0;
      Set(c);
    }
    void Process() {
      counter++;
      Serial << "Process " << name << " counter " << counter << endl;
    }
};

MyProc p1("proc0", 1000000UL);
MyProc p2("zopa1", 2000000UL);
MyProc p3("yuxa2", 3000000UL);

COOPTASK(c, &p1, &p2, &p3);

void setup () {
  Serial.begin(115200);
  Serial.println("Ready");
}

void loop() {
  c.run();
}
