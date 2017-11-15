#ifndef DONNEES_H_INCLUDED
#define DONNEES_H_INCLUDED

#define LENGTH_LINE 19

typedef struct hearBeat{
    int timestamp;
    int BPM;
}hearBeat;


void readCSV(FILE *f, hearBeat *HB);


void sort(int sizeCSV, hearBeat **HB, int (cmp)(hearBeat *, hearBeat *));



#endif // DONNEES_H_INCLUDED
