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
