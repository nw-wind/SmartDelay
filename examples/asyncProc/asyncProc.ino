
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
    void begin(const char *p, int c) {
      name = p;
      counter = c;
    }
    void Process() {
      counter++;
      Serial << "Process " << name << " counter " << counter << endl;
    }
};

#define P 3
MyProc p[P];

void setup () {
  Serial.begin(115200);
  p[0].begin("proc0", 1);
  p[1].begin("zopa1", 1);
  p[2].begin("yuxa2", 1);
  for (int i = 0; i < P; i++) p[i].Set(1000000UL * (i+1));
}

void loop() {
  for (int i = 0; i < P; i++) p[i].run();
  //delay(100);
}
