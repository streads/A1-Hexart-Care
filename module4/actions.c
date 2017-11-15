#include "actions.h"


int getLength(FILE *f){
    char temp[LENGTH_LINE];
    int i = 0;

    while(fgets(temp, LENGTH_LINE, f) != NULL)
    {
        i ++;
    }
    return i;
}


//On remplacera par la fonction qui prend la 1ère valeur du tri
hearBeat * getMax(hearBeat **HB, int n){
    int i = 1;
    int iFinal = 0;

    for(i = 1; i < n; i++){
        if(HB[i]->BPM > HB[iFinal]->BPM)
        {
            iFinal = i;
        }
    }
    return HB[iFinal];
}


////On remplacera par la fonction qui prend la dernière valeur du tri
hearBeat * getMin(hearBeat **HB, int n){
    int i = 1;
    int iFinal = 0;

    for(i = 1; i < n; i++){
        if(HB[i]->BPM < HB[iFinal]->BPM)
        {
            iFinal = i;
        }
    }
    return HB[iFinal];
}


float getAverage(hearBeat **HB, int sizeCSV){
    float temp = 0;
    int i;
    for(i=0; i<sizeCSV; i++)
    {
        temp += HB[i]->BPM;
    }
    return temp / sizeCSV;//A verifier peut-être qu'il compte la valeur 0
}


int bestBPM(hearBeat *a, hearBeat *b){
    if (a->BPM >= b->BPM){
        return 0;
    }else{
        return 1;
    }
}
