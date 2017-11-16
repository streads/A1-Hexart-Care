#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "donnees.h"
// #include "sort.h"


void UI(struct heartBeat *dataLoaded, int size){
  char choice; 
  int underTimestamp;
  int overTimestamp;  
  do {
    choice = showMenu();
  }while(choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '5' && choice != 'q');
  switch (choice){
    case '1':
      do{choice = showSubMenu1();}while(choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != 'q');
      if (choice == 'q'){return;}
      if (choice == '1' || choice == '2'){sort(size, dataLoaded, compare_by_date);}
      if (choice == '3' || choice == '4'){sort(size, dataLoaded, compare_by_BPM);}
      if(choice == '1' || choice == '3'){show(size, dataLoaded);}
      if(choice == '2' || choice == '4'){showReversed(size, dataLoaded);}
      do{choice = showBackMenu1();}while(choice != 'y' && choice != 'n');
      if(choice == 'y'){UI(dataLoaded, size);}else{return;}
      break;
    case '2':
      printf("_______________________________________________\n");   
      printf("Merci de suivre cettes syntaxe: timestamp1-timestamp2\n");   
      printf("Exemple: 1510793141-1510793154\n");
      scanf("%d-%d", &underTimestamp, &overTimestamp);
      printf("_______________________________________________\n");   
      sort(size, dataLoaded, compare_by_date);
      showInRange(size, dataLoaded, underTimestamp, overTimestamp);
      do{choice = showBackMenu1();}while(choice != 'y' && choice != 'n');
      if(choice == 'y'){UI(dataLoaded, size);}else{return;}
      break;
    case '3':
      sort(size, dataLoaded, compare_by_date);
      printf("\nY pour saisir une plage de donn%ce: \n[y]es / no: ", 130);
      if(getche() == 'y'){
        printf("_______________________________________________\n");   
        printf("Merci de suivre cettes syntaxe: timestamp1-timestamp2\n");   
        printf("Exemple: 1510793141-1510793154\n");
        scanf("%d-%d", &underTimestamp, &overTimestamp);
        printf("_______________________________________________\n");  
      }else{
        underTimestamp = dataLoaded[0].timestamp;
        overTimestamp = dataLoaded[size - 1].timestamp;  
      }
      int moy = moyInRange(size, dataLoaded, underTimestamp, overTimestamp);
      printf("Moyenne de pouls trouv%c entre %d et %d : %d\n", 130, underTimestamp, overTimestamp, moy);
      do{choice = showBackMenu1();}while(choice != 'y' && choice != 'n');
      if(choice == 'y'){UI(dataLoaded, size);}else{return;}
      break;
    case '4':
      sort(size, dataLoaded, compare_by_date);
      printf("\nY pour saisir une plage de donn%ce: \n[y]es / no: ", 130);
      if(getche() == 'y'){
        printf("_______________________________________________\n");   
        printf("Merci de suivre cettes syntaxe: timestamp1-timestamp2\n");   
        printf("Exemple: 1510793141-1510793154\n");
        scanf("%d-%d", &underTimestamp, &overTimestamp);
        printf("_______________________________________________\n");  
      }else{
        underTimestamp = dataLoaded[0].timestamp;
        overTimestamp = dataLoaded[size - 1].timestamp;  
      }
      int min = getFirstBPMInRage(size, dataLoaded, underTimestamp, overTimestamp);
      int max = getLastBPMInRage(size, dataLoaded, underTimestamp, overTimestamp);
      printf("\nValeur minimum de pouls trouv%c entre %d et %d : %d\n", 130, underTimestamp, overTimestamp, min);
      printf("Valeur maximum de pouls trouv%c entre %d et %d : %d\n", 130, underTimestamp, overTimestamp, max);
      do{choice = showBackMenu1();}while(choice != 'y' && choice != 'n');
      if(choice == 'y'){UI(dataLoaded, size);}else{return;}
      break;      
    case '5':
      system("cls");
      printf(" > Il y a actuellement %d pouls en memoire\n", size);
      do{choice = showBackMenu1();}while(choice != 'y' && choice != 'n');
      if(choice == 'y'){UI(dataLoaded, size);}else{return;}
      break;      
    case 'q':
      return;
      break;
  }
}

int main(int argc, char **argv) {
                                                        
  FILE *s;

  struct heartBeat *dataLoaded;


  if((s = fopen("beatLogger.csv", "r")) == NULL) {
    printf("Impossible d'ouvrir le fichier.");
    exit(-1);
  }

  int n = getLength(s, n);

  read(s, (struct heartBeat **)&dataLoaded, n); // ajouté

  UI(dataLoaded, n);

  fclose(s);
  free(dataLoaded);
  //free(dataSortedByBPM);
  return 0;
}

