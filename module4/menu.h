#include "donnees.h"

#ifndef MENU_H
#define MENU_H


void UI(struct heartBeat *dataLoaded, int size);


char showMenu();


char showSubMenu1();


char showBackMenu1();


void showReversed(int n, struct heartBeat *a);


void show(int n, struct heartBeat *a);


void showInRange(int n, struct heartBeat *a, int min, int max);


#endif // MENU_H
