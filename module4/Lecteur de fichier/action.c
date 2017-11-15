#include "action.h"


void readCSV(FILE *f, hearBeat **HB){
    char temp[LENGTH_LINE];
    int i = 0;
    while(fgets(temp, LENGTH_LINE, f) != NULL)
    {
        sscanf(temp, "%d;%d", &(HB[i]->timestamp), &(HB[i]->BPM));
        i ++;
    }
    return;
}


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


void sort(int sizeCSV, hearBeat **HB, int (cmp)(hearBeat *, hearBeat *)){
    //Thibault rempli avec son SUPER algorithme de tri fusion
}

void showInterface(hearBeat **HB_DateSort, hearBeat **HB_BPMSort, int sizeCSV){
    int i;
    short entree = 0;
    printf("Que voulez vous faire ?\n1. Afficher les données\n2. Afficher les données pour un temps particulier\n3. Afficher la moyenne de poul\n4. Afficher le nombre de pouls enregistré\n5. Afficher le maximum de poul\n6. Afficher le minimum de poul\n");
    scanf("%c", &entree);
    switch(entree)
    {
        case 1:
        {
            printf("Vous voulez :\n1. Afficher les données dans l'ordre croissant de temps\n2. Afficher les données dans l'ordre décroissant de temps\n3. Afficher les données dans l'ordre croissant de pouls\n4. Afficher les données dans l'ordre décroissant de pouls");
            scanf("%d", &entree);
            switch(entree)
            {
                case 1:
                {
                    //temps croissant
                    for(i=0; i<sizeCSV; i++)
                    {
                        printf("%d  -  %d", HB_DateSort[i]->BPM, HB_DateSort[i]->timestamp);
                    }
                    return;
                }
                case 2:
                {
                    //temps décroissant
                    for(i=sizeCSV; i>0; i--)
                    {
                        printf("%d  -  %d", HB_DateSort[i]->BPM, HB_DateSort[i]->timestamp);
                    }
                    return;
                }
                case 3:
                {
                    //poul croissant
                    for(i=0; i<sizeCSV; i++)
                    {
                        printf("%d  -  %d", HB_BPMSort[i]->BPM, HB_BPMSort[i]->timestamp);
                    }
                    return;
                }
                case 4:
                {
                    //poul décroissant
                    for(i=sizeCSV; i>0; i--)
                    {
                        printf("%d  -  %d", HB_BPMSort[i]->BPM, HB_BPMSort[i]->timestamp);
                    }
                    return ;
                }
            }
            return ;
        }
        case 2:
        {
            //Il faut faire la partie "Rechercher et afficher les données pour un temps particulier"
            printf("Cette partie est encore en construction");
            return;
        }
        case 3:
        {
            printf("La moyenne du pouls est de : %f", getAverage(HB_DateSort, sizeCSV));
            return;
        }
        case 4:
        {
            printf("Il y a %d pouls enregistrés", sizeCSV);
            return;
        }
        case 5:
        {
            hearBeat *max = getMax(HB_DateSort, sizeCSV);
            printf("Le poul le plus élevé est de %d", max->BPM);
            return;
        }
        case 6:
        {
            hearBeat *min = getMin(HB_DateSort, sizeCSV);
            printf("Le poul le plus bas est de %d", min->BPM);
            return;
        }
    }
    return;
}

int bestBPM(hearBeat *a, hearBeat *b){
    if (a->BPM >= b->BPM){
        return 0;
    }else{
        return 1;
    }
}
