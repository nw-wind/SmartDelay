# SmartDelay
The SmartDelay class for non blocking delays in arduino sketches.

I use this class for non-blocking delays or cooperative multitasking emulation.

    // Declaration
    SmartDelay var(delay_in_microseconds);

    loop () {
      if (var.Now()) {
        // The action after delay.
        // This code is executed each "delay_in_microseconds".
        // After this call the variable has been resetted for next delay. See Wait() method.
      }
      ...
    }

    var.Get(); // Get the current delay.
    
    old=var.Set(new_delay_micros);  // Set new delay interval and returns the old one.
    
    old=var.Wait(); Reset delay from right now.
