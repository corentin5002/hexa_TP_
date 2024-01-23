#include <stdio.h>
#include <malloc.h>
#include "./essai.h"


void parcours(maillon_t * file){

    int test = 1;
    while(test == 1){
        if (file -> next == NULL){
            test = 0;
        }

        printf("Valeur du maillon : %d\n", file->date);
        file = file -> next;
    }
}

// Affiche les valeurs successivement des maillons de la file
int afficherFile(maillon_t * file){

    printf("Value : %d\n", file -> date);

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

int freeFile(maillon_t * file){

    if (file->next == NULL){
        free(file);
        return 0;
    }

    freeFile(file->next);
    free(file);
}

void ajoutMaillonFin(maillon_t * file, int value){
    maillon_t * cursor = file;

    while(cursor -> next != NULL){
        cursor = cursor -> next ;
    }

    maillon_t * newMaillon = (maillon_t *) malloc(sizeof(maillon_t));
    newMaillon -> date = value;
    newMaillon -> next = NULL;

    cursor -> next = newMaillon;
}

int main(int argc , char ** argv)
{
    maillon_t * file = (maillon_t *) malloc(sizeof(maillon_t));

    parcours(file);

    for (int i = 100; i < 120; ++i) {
        ajoutMaillonFin(file, i);
        printf("i : %d", i);
    }
    afficherFile(file);
    freeFile(file);
    return 0;
}
