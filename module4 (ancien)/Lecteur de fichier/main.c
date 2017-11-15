#include <stdio.h>
#include <stdlib.h>

#include "action.c"


int main()
{
    FILE *csv = NULL;
    csv = fopen("./beatLogger.csv", "r");
    if (csv == NULL){
        printf("Impossible d'ouvrir le fichier beatLogger.csv\n");
        exit(1);
    }
    int sizeCSV = getLength(csv);
    hearBeat *HB_DateSort = malloc(sizeof(hearBeat)*sizeCSV);
    hearBeat *HB_BPMSort = malloc(sizeof(hearBeat)*sizeCSV);
    readCSV(csv, HB_DateSort);
    //Le HB est déjà trié par date
    readCSV(csv, (hearBeat **)HB_BPMSort);
    printf("TEST %d", HB_DateSort[0].   BPM);
    sort(sizeCSV, HB_BPMSort, bestBPM);
    short exitloop = 0;
    while(exitloop == 0)
    {
        exitloop = showInterface(HB_DateSort, HB_BPMSort, sizeCSV);
        system("cls");
    }
    printf("Salut a tous c'est Squeezie");

    return 0;
}
