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
int initLedPin(int pin[]);


int changeState(int index, int timeBeforeChangeAgain);
int tick();
void modeAll();
// function to turn on pins in function of the mode selected
void printLed(int mode);
#ifdef __cplusplus
} // extern "C"
#endif
#endif
