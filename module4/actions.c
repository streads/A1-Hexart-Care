#include <stdlib.h>
#include <stdio.h>

#include "actions.h"


int getLength(FILE *f){
    fseek(f, 0, SEEK_SET);
    char temp[LENGTH_LINE];
    int i = 0;

    while(fgets(temp, LENGTH_LINE, f) != NULL)
    {
        i ++;
    }
    return i;
}


int moyInRange(int n, struct heartBeat *a, int min, int max) {
  int i;
  int sum = 0;
  int counter = 0;
  for(i = 0; i < n; ++i) {
    if (min <= a[i].timestamp && a[i].timestamp <= max){
      sum += a[i].bpm;
      counter++;
    }
  }
  return sum/counter;
}


int getFirstBPMInRage(int n, struct heartBeat *a, int min, int max){
    int i;
    for(i = 0; i < n; ++i) {
    if (min <= a[i].timestamp && a[i].timestamp <= max){
      return a[i].bpm;
    }
  }
  return -1;
}


int getLastBPMInRage(int n, struct heartBeat *a, int min, int max){
  int i;
  for (i = n; i-- > 0; )
  {
    if (min <= a[i].timestamp && a[i].timestamp <= max){
      return a[i].bpm;
    }
  }
  return -1;
}
