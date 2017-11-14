#include "cardio.h"


void startCapture(hearbeat *HB, int startTime, int period){
  HB->beat =0;
  HB->startTime = 0;
  HB->period = 0;
  HB->isOver =0;
}

void beat(hearbeat *HB){
  HB->beat += 1;
}

void determineBPM(hearbeat *HB){
  HB->bpm = (HB->beat * 60) / HB->period;
}

int stopCapture(hearbeat *HB){
  HB->isOver =1;
  determineBPM(HB);
  return HB->bpm;
}

