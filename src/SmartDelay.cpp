#include <SmartDelay.h>

SmartDelay::SmartDelay(unsigned long tick) {
  smMicros = tick;
}
SmartDelay::~SmartDelay() {}
int SmartDelay::Now() {
  unsigned long mcs = micros();
  // Важно помнить про переполнение целого!
  if (mcs - smLast >= smMicros) {
    smLast = mcs;
    return true;
  } else {
    return false;
  }
}
unsigned long SmartDelay::Get() {
  return smMicros;
}
unsigned long SmartDelay::Set(unsigned long tick) {
  unsigned long old = smMicros;
  smMicros = tick;
  return old;
}
unsigned long SmartDelay::Wait() {
  unsigned long old = smMicros;
  smMicros = micros();
  return old;
}
// end of Smart Delay class definition

