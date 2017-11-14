#include "Arduino.h"
#include "coeur.h"
#include "param.h"

pinLed **LED = NULL;
short ledLength;
short lastLedIndex;

void initLedPin(int pin[]) {
  int i;
  ledLength = 14;

  LED = malloc(sizeof(pinLed) * ledLength);
  for (i = 0; i < ledLength; i++) {
    LED[i] = NULL;
  }
  for (i = 0; i < ledLength; i++) {
    pinLed *lcl = malloc(sizeof(pinLed));
    lcl->pin = pin[i];
    lcl->state = LOW;
    lcl->previousState = LOW;
    lcl->changeStateTime = 0;
    lcl->autoChange = 0;
    pinMode(lcl->pin, OUTPUT);
    LED[i] = lcl;
  }
}


void changeState(int i, int timeBeforeChangeAgain) {

  LED[i]->previousState = LED[i]->state;
  if (LED[i]->state == LOW) {
    LED[i]->state = HIGH;
  } else {
    LED[i]->state = LOW;
  }
  digitalWrite(LED[i]->pin, LED[i]->state);
  if (timeBeforeChangeAgain < 0) {
    LED[i]->autoChange = 0;
  } else {
    LED[i]->autoChange = 1;
    LED[i]->changeStateTime = millis() + timeBeforeChangeAgain;
  }
  lastLedIndex = i;
}

void tick() {
  int i;
  int z = millis();
  for (i = 0; i < ledLength; i++) {
    if(LED[i]->autoChange){
      if ((LED[i]->changeStateTime - z) < 0){
        changeState(i, -1);
      }
    }
  }
}

void modeAll() {
  int i = 0;
  for (i = 0; i < ledLength; i++) {
    if (LED[i] == NULL) {
      return;
    }
    changeState(i, millis() + 200);
  }
}
void modeOneByOne(){
  if (LED[lastLedIndex +1] != NULL){
    changeState(lastLedIndex +1, 200);
  }else{
    changeState(0, 200);
  }
}

void modeOneForX(){
  int i;
  for(i = 0; i < ledLength; i+=parameter){
    changeState(i, 200);
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
      changeState(parameter, 200);
      break;         
    default:
      modeAll();
      break;
  }
}

