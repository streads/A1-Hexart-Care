#include "Arduino.h"
#include "coeur.h"
#include "param.h"

int LED[20];
short ledLength;
short lastLedIndex = -1;

void initLedPin(int pin[], int Length) {
  ledLength = Length;
  int i;
  for(i = 0; i < ledLength; i++){
    LED[i] = pin[i];
    pinMode(pin[i], OUTPUT);
  }
}


void turnOn(int i) {
  digitalWrite(LED[i], HIGH);
  lastLedIndex = i;
 
}
void clearLed(){
  int i;
  for(i = 0; i < ledLength; i++){
    digitalWrite(LED[i], LOW);
  }
}

void modeAll() {
  int i = 0;
  for (i = 0; i < ledLength; i++) {
    turnOn(i);
  }
}
void modeOneByOne(){
  if (lastLedIndex < ledLength - 1){
    turnOn(lastLedIndex +1);
  }else{
    turnOn(0);
  }
}

void modeOneForX(){
  int i;
  for(i = 0; i < ledLength; i+=parameter){
    turnOn(i);
  }
}

void printLed() {
  switch (mode) {
    case 1:
      modeAll();
      break;
    case 2:
      modeOneForX();
      break;
    case 3:
      modeOneByOne();
      break;     
    case 4:
      turnOn(parameter);
      break;         
    default:
      modeAll();
      break;
  }
}

//void clearLed(){
//  int i =0;
//  for(i = 0; i<ledLength; i++){
//    if(LED[i] == NULL){return;}
//    if(LED[i]->state == HIGH){
//      changeState(i);
//    }
//  }
//}

