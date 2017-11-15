#ifndef COEUR_H
#define COEUR_H
#ifdef __cplusplus
extern "C" {
#endif


typedef struct outputPin {
  int pin;
  int state;
  int previousState;
  int changeStateTime;
  short autoChange;
}pinLed;


// this function will be call one times to store all pins leds
void initLedPin(int pin[], int Length);

//
void turnOn(int index);
void clearLed();
void modeAll();
void modeOneByOne();
void modeOneForX();
//// function to turn on pins in function of the mode selected
void printLed();
#ifdef __cplusplus
} // extern "C"
#endif
#endif
