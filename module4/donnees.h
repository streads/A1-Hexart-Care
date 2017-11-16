#include "stdio.h"
#ifndef DONNEES_H
#define DONNEES_H




#define LENGTH_LINE 30


typedef struct heartBeat {
    int timestamp;
    int bpm;
} ab;


void read(FILE *s, struct heartBeat **h, int m);


void sort(int n, struct heartBeat *a, int (cmp)(struct heartBeat *, struct heartBeat *));


void fuse(struct heartBeat *a, struct heartBeat *tmp, int s0, int e0, int s1, int e1, int (cmp)(struct heartBeat *, struct heartBeat *));


int compare_by_BPM(struct heartBeat *a, struct heartBeat *b);


int compare_by_date(struct heartBeat *a, struct heartBeat *b);


#endif // DONNEES_H
