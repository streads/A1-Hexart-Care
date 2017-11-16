#include "donnees.h"

int compare_by_BPM(struct heartBeat *a, struct heartBeat *b){
    if (a->bpm >= b->bpm){
        return 1;
    } else{
        return 0;
    }
}

int compare_by_date(struct heartBeat *a, struct heartBeat *b){
    if (a->timestamp >= b->timestamp){
        return 1;
    } else{
        return 0;
    }
}