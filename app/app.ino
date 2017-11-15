#include "Arduino.h"
#include "cardio.h"
#include "coeur.h"

const short sensorPin = 0;
const int recordTime = 10;
hearbeat *hb = NULL;

void SendCSV(int bpm){
  Serial.print("BPM: " );
  Serial.println(bpm);
}

void(* resetFunc) (void) = 0;
void setup() {
  Serial.begin(9600);
  hb = (struct hearbeat *)malloc(sizeof(struct hearbeat));
  hb->isOver = 1;
  
  int a[] ={2,3,4,5,6,7,8,9,10,11};
  initLedPin(a, 10);

}

void loop() {
  int sensorValue = analogRead(sensorPin);
  if(hb == NULL){exit(1);}

  if (hb->isOver == 0){

    if ((millis() - (hb->startTime + hb->period * 1000)) <= 0){
      modeAll();
      delay(1000);
      int bpm = stopCapture(hb);
      SendCSV(bpm);
      delay(4000);
      clearLed();
      resetFunc();
      //asm volatile ("jmp 0");  
    }
    

    if (processing(hb, sensorValue)){
      printLed();
      while(sensorValue > detectionLimit - 60){
        sensorValue = analogRead(sensorPin);
        delay(1);
      }
      clearLed();
    }
    
  }else{
    if (sensorValue > detectionLimit){
      // on demmare la capture
      modeAll();
      delay(1000);
      clearLed();
      startCapture(hb, millis(), 10);
      while(sensorValue > detectionLimit - 25){
        sensorValue = analogRead(sensorPin);
        delay(1);
      }
    }
  }
}


