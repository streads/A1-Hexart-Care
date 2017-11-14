// this file have to goal to test the coeur "librairy"
#include "Arduino.h"
#include "coeur.h"

void setup(){
  Serial.begin(9600);
  int pins[] = {2,3,4,5,6,7,8,9,10};
  initLedPin(pins);
  printLed(1);
  printLed(1);
  printLed(1);
  tick();

}

void loop(){
  tick();
  
}
