// fichier de test voir le dossier app pour voir le module cardio bien integré.
#include "Arduino.h"
#include "cardio.c"

const short sensorPin = 0;
const int detectionLimit = 380;
const int recordTime = 10;
hearbeat *hb = NULL;

int sensorValue;
int niceValue;
void SendCSV(int bpm){
  //Serial.println(bpm);
}


void setup() {
  Serial.begin(9600);
  hb = (struct hearbeat *)malloc(sizeof(struct hearbeat));
  Serial.println("Start coupture");
  startCapture(hb, millis(), recordTime);
}

void loop() {

  
  sensorValue = analogRead(sensorPin);
  if(hb == NULL){exit(1);}

  if (hb->isOver == 0){

    if (millis() - hb->startTime >= hb->period * 1000){
      Serial.print("Stopped capture BPM: ");
      Serial.print(hb->bpm);
      Serial.print(" nombre de battemnt: ");
      Serial.println(hb->beat);
      Serial.print(" en ");
      Serial.println(hb->period);
      stopCapture(hb);
      SendCSV(hb->bpm);
    }
    
    Serial.print(">");
    Serial.println(sensorValue);
    if (sensorValue > detectionLimit){
      Serial.println("Pou");      
      beat(hb);
      while(analogRead(sensorPin) > detectionLimit - 10){
        delay(0.1);
      }
    }
    
  }
}


