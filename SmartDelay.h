#if ARDUINO >= 100
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#ifndef SMART_DELAY_H
#define SMART_DELAY_H

#define SMART_DELAY_START 0
#define SMART_DELAY_STOP  1

class SmartDelay {
  private:
    unsigned long smMicros;
    unsigned long smLast;
    byte state=SMART_DELAY_START;
  public:
    inline SmartDelay() {}
    SmartDelay(unsigned long tick);
    ~SmartDelay();
    int Now();
    unsigned long Get();
    unsigned long Set(unsigned long tick);
    unsigned long Wait();
    unsigned long Reset();
    unsigned long Stop();
    unsigned long Start();
};

#endif
