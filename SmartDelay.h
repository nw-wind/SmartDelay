#ifndef SMART_DELAY_H
#define SMART_DELAY_H

#if ARDUINO >= 100
 #include <Arduino.h>
#endif

class SmartDelay {
  private:
    enum SMART_DELAY_STATE {
      SMART_DELAY_START,
      SMART_DELAY_STOP
    };

    unsigned long smMicros;
    unsigned long smLast;
    unsigned char state;

                  SmartDelay();
                  SmartDelay(const SmartDelay& rhs);
                  SmartDelay& operator= (const SmartDelay& rhs);

  public:
                  SmartDelay(unsigned long tick);

    int           Now();
    unsigned long Get() const;
    unsigned long Set(unsigned long tick);
    unsigned long Wait();
    unsigned long Reset();
    unsigned long Stop();
    unsigned long Start();
};

#endif
