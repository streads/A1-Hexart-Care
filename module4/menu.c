#include "stdio.h"
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
}

char showSubMenu1(char choice){
    system("cls");
    printf("||------------------------------------------------------||\n");
    printf("||       Menu : Choisisser le type d'affichage          ||\n");
    printf("||------------------------------------------------------||\n");
    printf("||--1-Croissant-par-date--------------------------------||\n");
    printf("||--2-Décroissant-par-date------------------------------||\n");
    printf("||--3-Croissant-par-pouls-------------------------------||\n");
    printf("||--4-Décroissant-par-pouls-----------------------------||\n");
    printf("||------------------------------------------------------||\n");   
    printf("||--q-Pour-quitter--------------------------------------||\n");       
    printf("Votre choix: ");
    return getche(); 
}
char showBackMenu1(char choice){
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