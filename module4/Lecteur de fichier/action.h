#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED

#define LENGTH_LINE 19

typedef struct hearBeat{
    int timestamp;
    int BPM;
}hearBeat;


void readCSV(FILE *f, hearBeat **HB);


int getLength(FILE *f);


hearBeat * getMax(hearBeat **HB, int n);


hearBeat * getMin(hearBeat **HB, int n);


float getAverage(hearBeat **HB, int sizeCSV);


void sort(int sizeCSV, hearBeat **HB, int (cmp)(hearBeat *, hearBeat *));


void showInterface(hearBeat **HB_DateSort, hearBeat **HB_BPMSort, int sizeCSV);

int bestBPM(hearBeat *a, hearBeat *b);

#endif // ACTION_H_INCLUDED
