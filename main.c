#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions/library.h"
#include "./functions/UI_functions.h"


int main(int argc , char ** argv)
{
    calendarEvent * calendar = (calendarEvent *) malloc(sizeof(calendarEvent));
    calendar->next = NULL;
    calendar->date = 0;

    int quit = 0;
    char * calendarName = (char *) malloc(sizeof(char) * 50);
    strcpy(calendarName, "no named calendar");

    initiateCalendar(calendar, 29052024, 1200, "t");
    addEvent(calendar, 28052024, 1100, "t");
    addEvent(calendar, 30052024, 1300, "t");


    while (!quit) {
        int selection = -1;
        selection = inputMenu(calendar, calendarName);

        switch (selection) {
            case 0:
                printf("\nAdd an event to your current calendar\n\n");
                inputEvent(calendar);

//                printCalendar(calendar);
                break;
            case 1:
                printf("Remove an event from your agenda\n\n");
                calendar = inputSupprEvent(calendar);
                break;
            case 2:
                printf("Show the calendar\n\n");
                printCalendar(calendar);
                break;
            case 3:
                printf("\nLoad a calendar\n\n");
                char * calendarNameToOpen = inputCalendarName();
                freeCalendar(calendar);
                calendar = openCalendar(calendarNameToOpen, calendarName);
                break;
            case 4:
                printf("Save your calendar\n\n");
                // Check if we have a name for the calendar
                char * calendarPathToSave;

                // If we don't have a name for the calendar yet
                if (strcmp(calendarName, "no named calendar") == 0) {
                    calendarPathToSave = inputCalendarName();

                    saveCalendar(calendar, calendarPathToSave);

                    // Update the name of the calendar
                    char * tempBuffer = strrchr(calendarPathToSave, '/');
                    strncpy(calendarName, "", 50);
                    strncpy(calendarName, tempBuffer, strlen(tempBuffer) - 4);

                    free(calendarPathToSave);
                } else {
                    calendarPathToSave = (char *) malloc(sizeof(char) * 70);
                    strcpy(calendarPathToSave, "./calendars/");
                    strcat(calendarPathToSave, calendarName);
                    strcat(calendarPathToSave, ".cld");

                    saveCalendar(calendar, calendarPathToSave);
                    free(calendarPathToSave);
                }

                break;
            case 5:
                printf("Quit the application\n\n");
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
                        printf("Goodbye and have a nice day !\n");
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
