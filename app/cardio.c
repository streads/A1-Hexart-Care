#include "cardio.h"

void startCapture(hearbeat *HB, int startTime, int period){
  HB->beat =0;
  HB->startTime = startTime;
  HB->period = period;
  HB->isOver =0;
}

void beat(hearbeat *HB){
  HB->beat += 1;
}

void determineBPM(hearbeat *HB){
  HB->bpm = ((HB->beat * 60) / HB->period);
}

int processing(hearbeat *HB, int sensorValue){
  if(sensorValue > detectionLimit){
    beat(HB);
    return 1;
  }else{
    return 0;
  }
  
}

int stopCapture(hearbeat *HB){
  HB->isOver =1;
  determineBPM(HB);
  return HB->bpm;
}

