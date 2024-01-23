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

int check_input_menu () {

    char agendaName[45] = "Ballade en terre du milieu";
    char input[10];
    int selection;

    do {
        printf("Hello and welcome to your calendar application !\n"
               "Here are the options available : \n\n"
               "0 - Add an event to your current calendar\n"
               "1 - Remove an event from your agenda\n"
               "2 - Show the calendar\n"
               "3 - Load a calendar\n"
               "4 - Export your calendar\n"
               "5 - Quit the application\n");

        printf("Current agenda used : \"%s\"\n", agendaName);

        printf("\nEnter a number between 0 and %d: ", MAX_VALUE_MENU);
        fgets(input, sizeof(input), stdin); // Read the entire line

        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        // Check the case the input isn't a digit
        if (input[0] < '0' || input[0] > '9') {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        // Convert the string to an integer
        selection = atoi(input);

        // Validate the number
        if (selection < 0 || selection > MAX_VALUE_MENU) {
            printf("Invalid input. Please enter a number between 0 and %d.\n", MAX_VALUE_MENU);
        } else {
            break; // Exit the loop if the input is valid
        }
    } while (1);

    printf("You entered: %d\n", selection);

    return selection;
}