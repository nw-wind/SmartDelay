# SmartDelay
The SmartDelay class for non blocking delays in arduino sketches.

I use this class for non-blocking delays or cooperative multitasking emulation.

    // Declaration
    SmartDelay var(delay_in_microseconds);

    loop () {
      // Typical code block.
      if (var.Now()) {
        // The action after delay.
        // This code is executed each "delay_in_microseconds".
        // The *var* has been resetted for next delay automatically. See Wait() method.
      }
      ...
    }

    var.Get(); // Get the current delay.
    
    old=var.Set(new_delay_micros);  // Set new delay interval and returns the old one.
    
    old=var.Wait(); Reset delay timer right now. Holds Now() for the next same period.
    
    old=var.Reset(); Let Now() return True next call.

The method Now() returns FALSE when the waiting time is not reached. It returns true if the internal timer is over and resets the timer again.

The method Get() just returns the current waiting interval.

The method Set() used for changing waiting time of fly. It returns the old timer.

The method Wait() returns the waiting time and reset the internal timer. It is useful to hold the timer. It prevents the method Now() to work. 

The method Reset() drops internal timer with no action. The next call of Now() returns True.

The method Stop() diallow Now to return True.

The mothod Start() allow Now to work.

====

Объектный вариант использования.

Есть виртуальный метод Process(), который надо переопределить. Этот метод будет вызываться каждый раз, когда приходит время, то есть, срабатывает встроенная Now(). Это позволяет не писать в loop слишком много.
```
class MyProc : public SmartDelay {
  public:
    void Process() {
      // что-то делается здесь
    }
};

#define P 3
MyProc p[P];

void setup () {
  for (int i=0; i<P; i++) p[i].Set(100000UL*i);
}

void loop() {
  for (int i=0; i<P; i++) p[i].run();
}
```
В примере методы pX.Process() будут выполняться асинхронно с разной периодичностью.

В проекте есть ещё контейнер процессов типа "гипервизора" чтобы одним вызовом в loop обойтись и без цикла.

```
class MyProc : public SmartDelay {
  public:
    MyProc(unsigned long c) : SmartDelay(c) {};
    void Process() {
      // что-то делается здесь
    }
};

MyProc p1(100000UL),p2(5000000UL),p3(250000UL); // Процессы и интервалы запуска

COOPTASK(c, &p1, &p2, &p3);

void loop() {
  c.run(); // Просессы p1..p3 будут выполняться по очереди с разным интервалом.
}
```
Динамическое размещение памяти отсутсвует. Всё статикой.
