#include "stdio.h"

#include "menu.h"


void UI(struct heartBeat *dataLoaded, int size){
  char choice;
  int underTimestamp;
  int overTimestamp;
  do {
    choice = showMenu();
  }while(choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '5' && choice != 'q');
  switch (choice){
  //Traite chaque cas correspondant à chaque option du menu, et redemande à chaque fois que la valeur n'est pas prise en compte
    case '1':
      do{choice = showSubMenu1();}while(choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != 'q');
      if (choice == 'q'){return;}
      if (choice == '1' || choice == '2'){sort(size, dataLoaded, compare_by_date);}
      if (choice == '3' || choice == '4'){sort(size, dataLoaded, compare_by_BPM);}
      if(choice == '1' || choice == '3'){show(size, dataLoaded);}
      if(choice == '2' || choice == '4'){showReversed(size, dataLoaded);}
      do{choice = showBackMenu1();}while(choice != 'y' && choice != 'n');
      if(choice == 'y'){UI(dataLoaded, size);}else{return;}
      //Affiche les sous menu et afficher l'information demandé par l'utilisateur, puis quitte ou retourne dans le menu principal
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
      //Demande un intervalle de temps en timestamp et affiche les données demandé par l'utilisateur, puis quitte ou retourne dans le menu principal
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
      //Demande un intervalle de temps en timestamp et affiche les données demandé par l'utilisateur, puis quitte ou retourne dans le menu principal
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
      //Demande un intervalle de temps en timestamp et affiche les données demandé par l'utilisateur, puis quitte ou retourne dans le menu principal
      break;
    case '5':
      system("cls");
      printf(" > Il y a actuellement %d pouls en memoire\n", size);
      do{choice = showBackMenu1();}while(choice != 'y' && choice != 'n');
      if(choice == 'y'){UI(dataLoaded, size);}else{return;}
      //Affiche le nombre de donnnées sauvegardé
      break;
    case 'q':
      return;
      //Retourne dans le main afin de fermer le programme
      break;
  }
}


char showMenu(){
    system("cls");
    printf("||------------------------------------------------------||\n");
    printf("||          Menu : Choisisser une option                ||\n");
    printf("||------------------------------------------------------||\n");
    printf("||--1-Afficher-les-donnees------------------------------||\n");
    printf("||--2-Chercher-dans-une-plage-horaire-------------------||\n");
    printf("||--3-Afficher-une-moyenne------------------------------||\n");
    printf("||--4-Afficher votre pouls minimum et maximum-----------||\n");
    printf("||--5-Nombre de donnees sauvegarde----------------------||\n");
    printf("||--q-Pour-quitter--------------------------------------||\n");
    printf("||------------------------------------------------------||\n");
    printf("Votre choix: ");
    return getche();
    //La fonction getche retourne la prochaine entrée du clavier
}


char showSubMenu1(){
    system("cls");
    printf("||------------------------------------------------------||\n");
    printf("||       Menu : Choisisser le type d'affichage          ||\n");
    printf("||------------------------------------------------------||\n");
    printf("||--1-Croissant-par-date--------------------------------||\n");
    printf("||--2-D%ccroissant-par-date------------------------------||\n", 130);
    printf("||--3-Croissant-par-pouls-------------------------------||\n");
    printf("||--4-D%ccroissant-par-pouls-----------------------------||\n", 130);
    printf("||------------------------------------------------------||\n");
    printf("||--q-Pour-quitter--------------------------------------||\n");
    printf("Votre choix: ");
    return getche();
}


char showBackMenu1(){
    //system("cls");
    printf("\n||------------------------------------------------------||\n");
    printf("||    Menu : Vouvez-vous retourner au menu principal    ||\n");
    printf("||------------------------------------------------------||\n");
    printf("||--[y]es-----------------------------------------------||\n");
    printf("||--[n]o------------------------------------------------||\n");
    printf("||------------------------------------------------------||\n");
    printf("Votre choix: ");
    return getche();
}


void showReversed(int n, struct heartBeat *a) {
  int i;
  system("cls");
  printf("            TIMESTAMP             BPM\n");
  printf("_______________________________________________\n");
  for (i = n; i-- > 0; )
  {
    printf("%18d %18d\n", a[i].timestamp, a[i].bpm);
  }
  printf("_______________________________________________\n");
}


void show(int n, struct heartBeat *a) {
  int i;
  system("cls");
  printf("            TIMESTAMP             BPM\n");
  printf("_______________________________________________\n");
  for(i = 0; i < n; ++i) {
    printf("%18d %18d\n", a[i].timestamp, a[i].bpm);
  }
  printf("_______________________________________________\n");
}


void showInRange(int n, struct heartBeat *a, int min, int max) {
  int i;
  system("cls");
  printf("            TIMESTAMP             BPM\n");
  printf("_______________________________________________\n");
  for(i = 0; i < n; ++i) {
    if (min <= a[i].timestamp && a[i].timestamp <= max){
      printf("%18d %18d\n", a[i].timestamp, a[i].bpm);
    }
  }
  printf("_______________________________________________\n");
}
