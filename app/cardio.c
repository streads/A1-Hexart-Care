#include "cardio.h"


// fonction permettant de charger des valeurs dans une structure heartBeat afin de lancer une capture
void startCapture(hearbeat *HB, int startTime, int period){
  HB->beat =0;
  HB->startTime = startTime;
  HB->period = period;
  HB->isOver =0;
}

// fonction ajoutant un battement a une structure heartbeat;
void beat(hearbeat *HB){
  HB->beat += 1;
}


// fonction permettant de recuperer le nombre de battement pas minute
void determineBPM(hearbeat *HB){
  // produit en croix permettant de determiné le nombre de battement par minute a l'aide d'un nombre de battement total sur un temps.
  HB->bpm = ((HB->beat * 60) / HB->period);
}

// compare une valeur a notre seuil de detection si elle est au-dessus alors on ajoute un battement et on retourne 1
int processing(hearbeat *HB, int sensorValue){
  if(sensorValue > detectionLimit){
    beat(HB);
    return 1;
  }else{
    return 0;
  }
  
}

// fonction appelé lorsque la capture doit s'arreter et retourne le BPM 
int stopCapture(hearbeat *HB){
  HB->isOver =1;
  determineBPM(HB);
  return HB->bpm;
}

