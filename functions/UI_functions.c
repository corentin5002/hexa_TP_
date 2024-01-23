#include "UI_functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkInputMenu(
        char * nameCalendar
) {

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

        printf("Current agenda used : \"%s\"\n", nameCalendar);

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

void showCalendar(calendarEvent * calendar){
    printf("Current calendar : \n");
    printf("|    Date    | Hour  | Commentary                                                             |\n"
           "|------------|-------|------------------------------------------------------------------------|\n"
           "| xx/xx/xxxx | 12:00 | TEST DEFAULT VALUE                                                zezef|\n"
    );
}