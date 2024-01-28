#include <stdio.h>
#include <stdlib.h>
#include "functions/library.h"
#include "./functions/UI_functions.h"


int main(int argc , char ** argv)
{
    calendarEvent * calendar = (calendarEvent *) malloc(sizeof(calendarEvent));
    calendar->next = NULL;
    calendar->date = 0;

    int quit = 0;
//    char
    char calendarName[50] = "Ballade en terre du milieu";

    while (!quit) {
        int selection = -1;
        selection = inputMenu(calendar, calendarName);

        switch (selection) {
            case 0:
                printf("\nAdd an event to your current calendar\n");
                inputEvent(calendar);

//                printCalendar(calendar);
                break;
            case 1:
                printf("Remove an event from your agenda\n");
                inputSupprEvent(calendar);
                break;
            case 2:
                printf("Show the calendar\n");
                printCalendar(calendar);
                break;
            case 3:
                printf("\nLoad a calendar\n");
                char * calendarNameToOpen = inputCalendarName(calendarName);
                printf("DEBUG : %s\n", calendarName);
                printf("DEBUG2 : %s\n", calendarNameToOpen);
                freeCalendar(calendar);
                calendar = openCalendar(calendarNameToOpen);
                break;
            case 4:
                printf("Export your calendar\n");
                break;
            case 5:
                printf("");
                int verifyQuit;
                verifyQuit = 0;
                while (!verifyQuit){
                    printf("Are you sure you want to quit ? (y/n): \n");

                    char input[2];
                    fgets(input, sizeof(input), stdin); // Read the entire line
                    clearInputBuffer();
                    if(input[0] == 'y'){
                        printf("\nQuitting the application\n");
                        freeCalendar(calendar);

                        verifyQuit = 1;
                        quit = 1;
                        printf("Goodbye and have a nice day !\n", quit);
                    } else if(input[0] == 'n'){
                        verifyQuit = 1;
                    } else {
                        printf("Invalid input. Please enter a number.\n");
                    }
                }
                break;
            default:
                break;
        }
    }

    return 0;
}
