#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED


int getLength(FILE *f);


hearBeat * getMax(hearBeat **HB, int n);


hearBeat * getMin(hearBeat **HB, int n);


float getAverage(hearBeat **HB, int sizeCSV);


int bestBPM(hearBeat *a, hearBeat *b);



#endif // ACTIONS_H_INCLUDED
