#include <stdio.h>

char showMenu(){
    system("cls");
    printf("||------------------------------------------------------||\n");
    printf("||       Menu : Configure ton battement de coeur        ||\n");
    printf("||------------------------------------------------------||\n");
    printf("||--1-Toutes-les-LEDs-clignotes-------------------------||\n");
    printf("||--2-Clignote-une-leds-sur-XXX-------------------------||\n");
    printf("||--3-Une-led-apr%cs-l'autre-----------------------------||\n", 232);
    printf("||--4-Une-seul-LED-clignote-au-choix--------------------||\n");
    printf("||--5-Pour-quitter--------------------------------------||\n");
    printf("||------------------------------------------------------||\n");   
    printf("Votre choix: ");
    return getche(); 
}

char showSubMenu(char choice){
    system("cls");
    printf("||------------------------------------------------------||\n");
    printf("||       Menu : Parametre supplementaire                ||\n");
    printf("||------------------------------------------------------||\n");
    if (choice == '2'){
        printf("||--Une-led-sur-combien-?---------------------------||\n");
    }else if(choice == '4'){
        printf("||--Quelle-LEDs-voulez-vous-allum%c-[0;9]----------------||\n", 130);
    }
    printf("||------------------------------------------------------||\n");   
    printf("||--q-Pour-quitter--------------------------------------||\n");       
    printf("Votre choix: ");
    return getche(); 
}