#include "SmartDelay.h"

SmartDelay::SmartDelay(unsigned long tick) {
  smMicros = tick;
  state    = SMART_DELAY_START;
}

int SmartDelay::Now() {
  unsigned long mcs = micros();
  // Важно помнить про переполнение целого!
  if (mcs - smLast < smMicros)
    return false;

  smLast = mcs;
  return (state == SMART_DELAY_START);
}

unsigned long SmartDelay::Get() const {
  return smMicros;
}

unsigned long SmartDelay::Set(unsigned long tick) {
  unsigned long old = smMicros;
  smMicros = tick;
  return old;
}

unsigned long SmartDelay::Wait() {
  unsigned long old = smMicros;
  smLast = micros();
  return old;
}

unsigned long SmartDelay::Reset() {
  unsigned long old = smMicros;
  smLast = 0; // про переполнение целого помнить!
  return old;
}

unsigned long SmartDelay::Start() {
  unsigned long old = smMicros;
  state = SMART_DELAY_START;
  return old;
}

unsigned long SmartDelay::Stop() {
  unsigned long old = smMicros;
  state = SMART_DELAY_STOP;
  return old;
}

// OOP methods
void SmartDelay::run() {
  if (Now()) Process();
}
virtual void SmartDelay::Process() {}
// end of Smart Delay class definition
