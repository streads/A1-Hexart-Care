#include "menu.h"


short showInterface(hearBeat **HB_DateSort, hearBeat **HB_BPMSort, int sizeCSV){
    int i;
    short entree = 0;
    printf("Que voulez vous faire ?\n1. Afficher les donnees\n2. Afficher les donnees pour un temps particulier\n3. Afficher la moyenne de poul\n4. Afficher le nombre de pouls enregistre\n5. Afficher le maximum de poul\n6. Afficher le minimum de poul\n7. Quitter\n");
    scanf("%hd", &entree);
    switch(entree)
    {
        case 1:
        {
            system("cls");
            showInterfaceCase1(HB_DateSort, HB_BPMSort, sizeCSV);
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
            printf("La moyenne du pouls est de : %f", getAverage(HB_DateSort, sizeCSV));
            return 0;
        }
        case 4:
        {
            printf("Il y a %d pouls enregistrés", sizeCSV);
            return 0;
        }
        case 5:
        {
            hearBeat *max = getMax(HB_DateSort, sizeCSV);
            printf("Le poul le plus élevé est de %d", max->BPM);
            return 0;
        }
        case 6:
        {
            hearBeat *min = getMin(HB_DateSort, sizeCSV);
            printf("Le poul le plus bas est de %d", min->BPM);
            return 0;
        }
        case 7:
        {
            return 1;
        }
        default:
        {
            system("cls");
            printf("Vous devez entrer un chiffre entre 1 et 7\n");
            showInterface(HB_DateSort, HB_BPMSort, sizeCSV);
            return 0;
        }
    }
    return 0;
}


void showInterfaceCase1(hearBeat **HB_DateSort, hearBeat **HB_BPMSort, int sizeCSV){
    short entree;
    int i;
    printf("Vous voulez :\n1. Afficher les donnees dans l'ordre croissant de temps\n2. Afficher les donnees dans l'ordre decroissant de temps\n3. Afficher les donnees dans l'ordre croissant de pouls\n4. Afficher les donnees dans l'ordre decroissant de pouls\n5. Retour\n");
    scanf("%hd", &entree);
    switch(entree)
    {
        case 1:
        {
            //temps croissant
            for(i=0; i<sizeCSV; i++);
            {
                printf("%  -  %d", HB_DateSort[i]->BPM, HB_DateSort[i]->timestamp);
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
            return;
        }
        case 5:
        {
            return;
        }
        default:
        {
            system("cls");
            printf("Vous devez entrer un nombre entre 1 et 5\n");
            showInterfaceCase1(HB_DateSort, HB_BPMSort, sizeCSV);
            return;
        }
    }
    return;
}
