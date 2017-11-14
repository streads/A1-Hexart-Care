#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED

#define LENGTH_LINE 19

typedef struct hearBeat{
    int timestamp;
    int BPM;
}hearBeat


int readCSV(hearBeat **HB);


hearBeat getMax(hearBeat **HB);


void getMin(hearBeat **HB);


float getAverage(hearBeat **HB, int nbEntree);


void sort(hearBeat **HB, *(Cmp));


void showInterface(void);


#endif // ACTION_H_INCLUDED
