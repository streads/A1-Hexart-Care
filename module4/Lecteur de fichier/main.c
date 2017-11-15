#include <stdio.h>
#include <stdlib.h>

#include "action.c"


int main()
{
    FILE *csv = NULL;
    fopen(csv, "beatLogger.csv");
    if (csv == NULL){
        printf("Impossible d'ouvrir le fichier beatLogger.csv\n");
        exit(1);
    }
    int sizeCSV = getLength(csv);
    hearBeat **HB_DateSort = malloc(sizeof(hearBeat)*sizeCSV);
    hearBeat **HB_BPMSort = malloc(sizeof(hearBeat)*sizeCSV);
    readCSV(csv, HB_DateSort);
    readCSV(csv, HB_BPMSort);
    sort(sizeCSV, HB_BPMSort, bestBPM);


    //Le HB est trié par date
    return 0;
}
