#ifndef SMART_DELAY_H
#define SMART_DELAY_H

class SmartDelay {
  private:
    unsigned long smMicros;
    unsigned long smLast;
  public:
    SmartDelay(unsigned long tick);
    ~SmartDelay();
    int Now();
    unsigned long Get();
    unsigned long Set(unsigned long tick);
    unsigned long Wait();
};

#endif
