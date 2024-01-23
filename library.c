#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Affiche les valeurs successivement des maillons de la file
// Refaire une fonction pour une non récursive
int afficherFile(maillon_t * file){

    printf("[%d : %d] : %s\n", file->date, file->heure, file->commentaire);

    if (file -> next == NULL){
        return 0;
    }

    return afficherFile(file->next);
}

int popFile(maillon_t * file){
    maillon_t * cursor = file;

    while(cursor -> next -> next != NULL){
        cursor = cursor -> next ;
    }

    int valueLast = cursor -> next -> date;
    free(cursor -> next);

    cursor -> next = NULL;

    return valueLast;
}

//refaire fonction pour une non récursive
int freeFile(maillon_t * file){

    if (file->next == NULL){
        free(file);
        return 0;
    }

    freeFile(file->next);
    free(file);
    return 0;
}

void ajoutMaillonFin(maillon_t * file, int date, int heure, char * commentaire){
    maillon_t * cursor = file;

    while(cursor -> next != NULL){
        cursor = cursor -> next ;
    }
    maillon_t * newMaillon = (maillon_t *) malloc(sizeof(maillon_t));

    newMaillon -> date = date;
    newMaillon -> heure = heure;
    strcpy(newMaillon -> commentaire, commentaire);
    newMaillon -> next = NULL;

    cursor -> next = newMaillon;
}

int dateStrToInt(char * date){

//    char * newDate = (char *) malloc(sizeof(char)*)

//    int jour, mois, annee;
//    printf("Rentrez valeurs de la date : \n");
//    scanf("%d-%d-%d", &jour, &mois, &annee);



    return 0;
}