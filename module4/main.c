#include <stdlib.h>
#include <stdio.h>

#include "menu.h"
#include "donnees.h"
#include "actions.h"


int main(int argc, char **argv) {

  FILE *s = NULL;

  struct heartBeat *dataLoaded;


  if((s = fopen("beatLogger.csv", "r")) == NULL) {
    printf("Impossible d'ouvrir le fichier.");
    exit(-1);
  }

  int n = getLength(s);

  read(s, (struct heartBeat **)&dataLoaded, n); // ajouté

  UI(dataLoaded, n);

  fclose(s);
  free(dataLoaded);
  //free(dataSortedByBPM);
  return 0;
}
