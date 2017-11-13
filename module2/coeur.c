#include "Arduino.h"
#include "coeur.h"
pinLed *LED = NULL;
short ledLength;


void initLedPin(int pin[]){
  LED = (struct outputPin *)malloc(sizeof(struct outputPin));
  LED->next = NULL;
  int length = sizeof(pin) / sizeof(int);
  int i;
  for(i = 0; i < length; i++){
    pinMode(pin[i], OUTPUT);
    addChild(pin[i]);
  }
}

void addChild(int pin){
  int i;
  pinLed *ptrLed = LED;
  while(ptrLed->next != NULL){
    ptrLed = ptrLed->next;
  }
  ptrLed->next =  (struct outputPin *)malloc(sizeof(struct outputPin));
  ptrLed->next->pin = pin;
  ptrLed->next->state = LOW;
  ptrLed->next->previousState = LOW;
  ptrLed->next->next = NULL;
  ledLength += 1;
}

void changeState(pinLed *led){
  led->previousState = led->state;
  led->state = !led->state;
  digitalWrite(led->pin, led->state);

}
void tick(){

  int tickTime = millis();
  int i = 0;
  pinLed *ptrLed = LED;

  while(i < ledLength){
    if (ptrLed->changeStateTime > 0){
      if (ptrLed->changeStateTime - tickTime < 0){
        ptrLed->changeStateTime = -1;
        changeState(ptrLed);
      }
    }

    ptrLed = ptrLed->next;
  }

}
void modeAll(){
  int i = 0;
  pinLed *ptrLed = LED;
  while(i < ledLength){
    changeState(ptrLed);
    ptrLed->changeStateTime = millis() + 200;
    ptrLed  = ptrLed->next;
  }
}

void beat(int mode){
  switch (mode) {
    case 0:
      modeAll();
      break;
    default:
      beat(0);
  }
}
