#include "donnees.h"


void readCSV(FILE *f, hearBeat *HB){
    char temp[LENGTH_LINE];
    int i = 0;
    while(fgets(temp, LENGTH_LINE, f) != NULL)
    {
        sscanf(temp, "%d;%d", &(HB[i].timestamp), &(HB[i].BPM));
        i ++;
    }
    return;
}


void sort(int sizeCSV, hearBeat **HB, int (cmp)(hearBeat *, hearBeat *)){
    //Thibault rempli avec son SUPER algorithme de tri fusion
}
