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


hearBeat getMax(hearBeat **HB){
    int i = 1;
    int iFinal = 0;
    while(HB[i] != NULL)
    {
        if(HB[iFinal] < HB[i])
        {
            iFinal = i;
        }
        i ++;
    }
    return iFinal;
}


hearBeat getMin(hearBeat **HB){
    int i = 1;
    int iFinal = 0;
    while(HB[i] != NULL)
    {
        if(HB[iFinal] > HB[i])
        {
            iFinal = i;
        }
        i ++;
    }
    return iFinal;
}


float getAverage(hearBeat **HB){

}


void sort(hearBeat **HB, *(Cmp)){
    //Thibault rempli avec son SUPER algorithme de tri fusion
}

void showInterface(void){
    short entree = 0;
    printf("Que voulez vous faire ?\n1. Afficher les donn�es\n2. Afficher les donn�es pour un temps particulier\n3. Afficher la moyenne de poul\n4. Afficher le nombre de pouls enregistr�\n5. Afficher le maximum de poul\n6. Afficher le minimum de poul\n");
    scanf("%c", entree);
    switch(entree)
    {
        case 1:
        {
            printf("Vous voulez :\n1. Afficher les donn�es dans l'ordre croissant de temps\n2. Afficher les donn�es dans l'ordre d�croissant de temps\n3. Afficher les donn�es dans l'ordre croissant de pouls\n4. Afficher les donn�es dans l'ordre d�croissant de pouls");
            scanf("%d", entree);
            switch(entree)
            {
                case 1:
                {
                    //temps croissant
                    return 0;
                }
                case 2:
                {
                    //temps d�croissant
                    return 0;
                }
                case 3:
                {
                    //poul croissant
                    return 0;
                }
                case 4:
                {
                    //poul d�croissant
                    return 0;
                }
            }
            return 0;
        }
        case 2:
        {
            //Il faut faire la partie "Rechercher et afficher les donn�es pour un temps particulier"
            printf("Cette partie est encore en construction");
            return 0;
        }
        case 3:
        {
            printf("La moyenne du pouls est de : %f", getAverage(HB));
            return 0;
        }
        case 4:
        {
            printf("Il y a %d pouls enregistr�s", nbEntr�es);
            return 0;
        }
        case 5:
        {
            hearBeat max = getMax(HB);
            printf("Le poul le plus �lev� est de %d", max.BPM);
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
