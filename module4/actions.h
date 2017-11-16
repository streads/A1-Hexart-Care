#include "donnees.h"
#ifndef ACTIONS_H
#define ACTIONS_H



int getLength(FILE *f);
void sort(int n, struct heartBeat *a, int (cmp)(struct heartBeat *, struct heartBeat *));


void read(FILE *s, struct heartBeat **h, int m);


void showReversed(int n, struct heartBeat *a);


void showInRange(int n, struct heartBeat *a, int min, int max);


void show(int n, struct heartBeat *a);



int moyInRange(int n, struct heartBeat *a, int min, int max);


int getFirstBPMInRage(int n, struct heartBeat *a, int min, int max);


int getLastBPMInRage(int n, struct heartBeat *a, int min, int max);


#endif // ACTIONS_H
