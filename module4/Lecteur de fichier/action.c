#include "action.h"


int readCSV(hearBeat **HB){
    char temp[LENGTH_LINE];
    FILE *f = NULL;
    f = fopen;
    int i = 0;
    while(fgets(temp, LENGTH_LINE, f) != NULL)
    {
        sscanf(temp, "%d;%d", &(hearBeat[i].timestamp), &(hearBeat[i].BPM));
        i ++
    }
    return i -1;
}


//On remplacera par la fonction qui prend la 1ère valeur du tri
hearBeat getMax(hearBeat **HB){
    int i = 1;
    int iFinal = 0;
    while(hearBeat[i].BPM != NULL)
    {
        if(hearBeat[iFinal].BPM < hearBeat[i].BPM)
        {
            iFinal = i;
        }
        i ++;
    }
    return iFinal;
}


////On remplacera par la fonction qui prend la dernière valeur du tri
hearBeat getMin(hearBeat **HB){
    int i = 1;
    int iFinal = 0;
    while(hearBeat[i].BPM != NULL)
    {
        if(hearBeat[iFinal].BPM > hearBeat[i].BPM)
        {
            iFinal = i;
        }
        i ++;
    }
    return iFinal;
}


float getAverage(hearBeat **HB, int nbEntree){
    float temp = hearBeat[0].BPM;
    while(hearBeat[i].BPM != NULL)
    {
        temp += hearBeat[i].BPM;
        i ++
    }
    return temp / nbEntree;//A verifier peut-être qu'il compte la valeur 0
}


void sort(hearBeat **HB, *(Cmp)){
    //Thibault rempli avec son SUPER algorithme de tri fusion
}

void showInterface(void){
    short entree = 0;
    printf("Que voulez vous faire ?\n1. Afficher les données\n2. Afficher les données pour un temps particulier\n3. Afficher la moyenne de poul\n4. Afficher le nombre de pouls enregistré\n5. Afficher le maximum de poul\n6. Afficher le minimum de poul\n");
    scanf("%c", entree);
    switch(entree)
    {
        case 1:
        {
            printf("Vous voulez :\n1. Afficher les données dans l'ordre croissant de temps\n2. Afficher les données dans l'ordre décroissant de temps\n3. Afficher les données dans l'ordre croissant de pouls\n4. Afficher les données dans l'ordre décroissant de pouls");
            scanf("%d", entree);
            switch(entree)
            {
                case 1:
                {
                    //temps croissant
                    sort((HB, byDate))
                    for(i=0; i<nbEntree; i++)
                    {
                        printf("%d  -  %d", hearBeat[i].BPM, hearBeat[i].timestamp)
                    }
                    return 0;
                }
                case 2:
                {
                    //temps décroissant
                    sort((HB, byDate))
                    for(i=nbEntree; i>0; i--)
                    {
                        printf("%d  -  %d", hearBeat[i].BPM, hearBeat[i].timestamp)
                    }
                    return 0;
                }
                case 3:
                {
                    //poul croissant
                    sort((HB, byBPM))
                    for(i=0; i<nbEntree; i++)
                    {
                        printf("%d  -  %d", hearBeat[i].BPM, hearBeat[i].timestamp)
                    }
                    return 0;
                }
                case 4:
                {
                    //poul décroissant
                    sort((HB, byBPM))
                    for(i=nbEntree; i>0; i--)
                    {
                        printf("%d  -  %d", hearBeat[i].BPM, hearBeat[i].timestamp)
                    }
                    return 0;
                }
            }
            return 0;
        }
        case 2:
        {
            //Il faut faire la partie "Rechercher et afficher les données pour un temps particulier"
            printf("Cette partie est encore en construction");
            return 0;
        }
        case 3:
        {
            printf("La moyenne du pouls est de : %f", getAverage(HB, nbEntree));
            return 0;
        }
        case 4:
        {
            printf("Il y a %d pouls enregistrés", nbEntrées);
            return 0;
        }
        case 5:
        {
            hearBeat max = getMax(HB);
            printf("Le poul le plus élevé est de %d", max.BPM);
            return 0;
        }
        case 6:
        {
            hearBeat min = getMin(HB);
            printf("Le poul le plus bas est de %d", min.BPM)
            return 0;
        }
    }

}
