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
  struct outputPin *next;
}pinLed;


// this function will be call one times to store all pins leds
void initLedPin();

void addChild(int pin);
void changeState(pinLed *led);
void tick();
void modeAll();
// function to turn on pins in function of the mode selected
void beat(int mode);
#ifdef __cplusplus
} // extern "C"
#endif
#endif
