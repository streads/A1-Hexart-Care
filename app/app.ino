#include "Arduino.h"
#include "cardio.h"
#include "coeur.h"

const short sensorPin = 0;
const int detectionLimit = 380;
const int recordTime = 10;
hearbeat *hb = NULL;

void SendCSV(int bpm){
  Serial.println(bpm);
}


void setup() {
  Serial.begin(9600);
  hb = (struct hearbeat *)malloc(sizeof(struct hearbeat));
  Serial.println("Start coupture");
  startCapture(hb, millis(), recordTime);
}

void loop() {

  
  int sensorValue = analogRead(sensorPin);
  if(hb == NULL){exit(1);}

  if (hb->isOver == 0){

    if ((millis() - hb->startTime) >= (hb->period * 1000)){
      stopCapture(hb);
      SendCSV(hb->bpm);
    }
    
    Serial.print(">");
    Serial.println(sensorValue);
    if (sensorValue > detectionLimit){
      printLed();
      beat(hb);
      while(analogRead(sensorPin) > detectionLimit - 10){
        delay(0.1);
      }
    }
    
  }
}


