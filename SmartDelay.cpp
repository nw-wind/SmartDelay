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
    if (state==SMART_DELAY_START) return true;
    else return false;
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
  state=SMART_DELAY_START;
  return old;
}
unsigned long SmartDelay::Stop() {
  unsigned long old = smMicros;
  state=SMART_DELAY_STOP;
  return old;
}
// end of Smart Delay class definition
