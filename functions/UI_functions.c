#include "UI_functions.h"
#include "library.h"
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


    switch (selection) {
        case 0:
            printf("Add an event to your current calendar\n");
            break;
        case 1:
            printf("Remove an event from your agenda\n");
            break;
        case 2:
            printf("Show the calendar\n");
            break;
        case 3:
            printf("Load a calendar\n");
            break;
        case 4:
            printf("Export your calendar\n");
            break;
        case 5:
            printf("Quit the application\n");
            break;
        default:
            break;
    }

    return selection;
}

void inputEvent(/*calendarEvent * calendar*/){
    printf("Enter the date of the event with this format : 'dd/mm/yyyy'\n");
    char inputDate[11], inputHour[6], inputComment[200];
    int day, month, year, hour, minute;

    fgets(inputDate, sizeof(inputDate), stdin);

    //sscanf return the number of strings succesfully read
    if(sscanf(inputDate, "%d/%d/%d", &day, &month, &year) == 3) {
        printf("day : %d\nmonth : %d\nyear : %d\n", day, month, year);
    } else {
        printf("Invalid input. Please enter a date with this format : 'dd/mm/yyyy'\n");
    }

    printf("Enter the hour of the event with this format : 'hh:mm'\n");
    fgets(inputHour, sizeof(inputHour), stdin);

    if(sscanf(inputDate, "%d:%d", &hour, &minute) == 2) {
        printf("time of the day %d:%d\n", hour, minute);
    } else {
        printf("Invalid input. Please enter a date with this format : 'hh:mm'\n");
    }

    printf("Enter your commentary, a short description of the event (200char maximum)\n");
    fgets(inputComment, sizeof(inputComment), stdin);

    calendarEvent * newEvent = (calendarEvent *) malloc(sizeof(calendarEvent));

//    newEvent -> date
}


void printCalendar(calendarEvent *calendar) {
    calendarEvent *cursor = calendar;

    printf("State of current calendar : \n\n");
    printf("|    Date    | Hour  | Commentary \n"
           "|------------|-------|------------------------------------------------------------------------>\n"
    );

    while (cursor != NULL) {
        // Conversion from int to str formatted
        char strDate[11], strHour[6];

        dateIntToStr(cursor->date, strDate);
        hourIntToStr(cursor->hour, strHour);

        printf("| %s | %s | %s \n", strDate, strHour, cursor->commentary);
        cursor = cursor->next;
    }
}

void inputSupprEvent(calendarEvent *calendar){
    calendarEvent *cursor = calendar;

    int selectionList = 0;
    int selection = -1;
    char input[5];

    printf("State of current calendar : \n\n");
    printf("| n° |    Date    | Hour  | Commentary \n"
           "|----|------------|-------|------------------------------------------------------------------------>\n"
    );

    while (cursor != NULL) {
        // Conversion from int to str formatted
        char strDate[11], strHour[6];


        dateIntToStr(cursor->date, strDate);
        hourIntToStr(cursor->hour, strHour);

        printf("| %d | %s | %s | %s \n", selectionList , strDate, strHour, cursor->commentary);
        cursor = cursor->next;
        selectionList += 1;
    }

    do {
        printf("\nEnter the number of the event you want to delete : ");
        fgets(input, sizeof(input), stdin);

        if((sscanf(input, "%d", &selection) == 1) && (selection >= 0) && (selection < selectionList)){
            calendarEvent * eventToSuppr =  findEvent(calendar, selection);

            char strDate[11], strHour[6];

            dateIntToStr(eventToSuppr->date, strDate);
            hourIntToStr(eventToSuppr->hour, strHour);

            printf(
                    "\nYou entered : %d \nEvent to suppress | %s | %s | %s\n",
                    selection,
                    strDate,
                    strHour,
                    eventToSuppr->commentary
                    );

            suppressEvent(calendar, eventToSuppr->date, eventToSuppr->hour);

        } else {
            printf("Invalid input. Please enter a number between 0 and %d.\n", selectionList);
        }
    }while(selection == -1);

}