#ifndef SMART_DELAY_H
#define SMART_DELAY_H

#if ARDUINO >= 100
 #include <Arduino.h>
#endif

class SmartDelay {
  private:
    enum SMART_DELAY_STATE {
      SMART_DELAY_START=0,
      SMART_DELAY_STOP
    };

    unsigned long smMicros;
    unsigned long smLast;
    unsigned char state;

  public:
    SmartDelay(){
      smMicros = 0;
      state    = SMART_DELAY_START;
    };
    SmartDelay(const SmartDelay& rhs);
    SmartDelay& operator= (const SmartDelay& rhs);
    SmartDelay(unsigned long tick);

    int           Now();
    unsigned long Get() const;
    unsigned long Set(unsigned long tick);
    unsigned long Wait();
    unsigned long Reset();
    unsigned long Stop();
    unsigned long Start();
 
    // OOP methods
    void run(); // to pun into loop()
    virtual void Process(); // to overload
};

#define SMART_DELAY_PROCESSES(name, ...) SmartDelay *name[]={__VA_ARGS__}
#define SMART_DELAY_PROCCOUNT(name) (sizeof(name)/sizeof(SmartDelay*))
#define COOPTASK(name, ...) SMART_DELAY_PROCESSES(Proc_Pointers_Array_name, __VA_ARGS__); coopTask name(Proc_Pointers_Array_name, SMART_DELAY_PROCCOUNT(Proc_Pointers_Array_name))

class coopTask {
  private:
    SmartDelay **p;
    unsigned int count;
  public:
    coopTask() {};
    coopTask(SmartDelay **arr, unsigned int c) {
      p = arr;
      count=c;
    }
    void run() {
      for (int i = 0; i < count; i++) p[i]->run();
    }
};

#endif
