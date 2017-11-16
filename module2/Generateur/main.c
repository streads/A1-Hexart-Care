#include "stdio.h"
#include "menu.h"
#include "generateCode.h"


int main(int argc, char **argcv){

    FILE* f = NULL;
    f = fopen("app/param.h","w"); // on ouvre le fichier app/param.h en mode d'écriture
    if (f == NULL){
        printf("Impossible d'ouvrir le fichier");
        return 1;
    }
    char choice1 = 1;
    char choice2 = 1;
    char choice3;
    do
        {

            choice1 = showMenu();
            printf("\n");
        }
    while(choice1 != '1' && choice1 != '2' && choice1 != '3' && choice1 != '4' && choice1 != '5');
    if (choice1 == '5'){
        return 0;
    }
    if (choice1 == '2' || choice1 == '4'){
        do
            {
                system("cls");
                choice2 = showSubMenu(choice1);
                printf("\n");
            }
        while(choice2 != 'q' && choice2 != '1' && choice2 != '2' && choice2 != '3' && choice2 != '4' && choice2 != '5' && choice2 != '6' && choice2 != '7' && choice2 != '8' && choice2 != '9' && choice2 != '0');
    }
    if (choice1 == 'q'){
        return 0;
    }
    system("cls");
    createFile(f, choice1, choice2); // appel de la fonction ecrivant dans notre fichier param.h les parametres d'allumage des leds
    fclose(f);
    printf("Fichier g%cn%cr%c.\n", 130, 130, 130);
    printf("Voulez vous le transferer sur l'arduino ?\n");

    do {
        printf("[y]es / [n]o: ");
        choice3  = getche();

    }while(choice3 != 'y' && choice3 != 'n');

    if(choice3 == 'y'){
        printf("Envoi en cours . . .\n");
        // permet d'envoyer un projet ino sur un arduino branché en usb
        system("arduino_debug.exe --upload app/app.ino");

    }

    return 0;
}
