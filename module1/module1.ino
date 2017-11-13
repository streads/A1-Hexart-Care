#include "Arduino.h"
#include "cardio.c"

const short sensorPin = 0;
const int detectionLimit = 1;
const int recordTime = 15;
hearbeat *hb = NULL;

int sensorValue;
int niceValue;
void SendCSV(int bpm){
  //Serial.println(bpm);
}


void setup() {
  Serial.begin(9600);
  hb = (struct hearbeat *)malloc(sizeof(struct hearbeat));
  startCapture(hb, millis(), recordTime);
}

void loop() {

  
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  if(hb == NULL){exit(1);}

  if (hb->isOver == 0){

    if (millis() - hb->startTime >= hb->period){
      stopCapture(hb);
      SendCSV(hb->bpm);
    }
    

    if (sensorValue > detectionLimit){
      beat(hb);
      //delay(0.2);
    }
    
  }
}


