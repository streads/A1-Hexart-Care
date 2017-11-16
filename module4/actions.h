#include "donnees.h"
#ifndef ACTIONS_H
#define ACTIONS_H


int getLength(FILE *f);


int moyInRange(int n, struct heartBeat *a, int min, int max);


int getFirstBPMInRage(int n, struct heartBeat *a, int min, int max);


int getLastBPMInRage(int n, struct heartBeat *a, int min, int max);


#endif // ACTIONS_H
