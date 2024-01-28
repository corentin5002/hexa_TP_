#include "UI_functions.h"
#include "library.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int inputMenu(calendarEvent * calendar, char * nameCalendar) {

    char input[10];
    int selection;

    do {
        printf("You are working with the calendar named : %s\n"
               "Here are the options available : \n\n"
               "0 - Add an event to your current calendar\n"
               "1 - Remove an event from your agenda\n"
               "2 - Show the calendar\n"
               "3 - Load a calendar\n"
               "4 - Export your calendar\n"
               "5 - Quit the application\n", nameCalendar);

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

    printf("DEBUG You entered: %d\n", selection);

    return selection;
}

void inputEvent(calendarEvent * calendar){
    char inputDate[11], inputHour[6], inputComment[200];
    int day, month, year, hour, minute;

    int isValidInput = 0;
    //sscanf return the number of strings succesfully read
    do {
        printf("Enter the date of the event with this format : 'dd/mm/yyyy'\n-> : ");
        fgets(inputDate, sizeof(inputDate), stdin);
        clearInputBuffer();

        if(sscanf(inputDate, "%02d/%02d/%04d", &day, &month, &year) == 3 && checkDateValue(day, month, year)) {
            printf("DEBUG Date input : %02d/%02d/%04d\n", day, month, year);
            isValidInput = 1;

        } else {
            printf("/!\\ Invalid input. Please enter a date with this format : 'dd/mm/yyyy'\n");
        }

    } while(!isValidInput);

    isValidInput = 0;
    do {
        printf("\nEnter the hour of the event with this format : 'hh:mm'\n-> : ");
        fgets(inputHour, sizeof(inputHour), stdin);
        clearInputBuffer();

        if(sscanf(inputHour, "%02d:%02d", &hour, &minute) == 2 && checkHourValue(hour, minute)) {
            printf("DEBUG Hour input %02d:%02d\n", hour, minute);
            isValidInput = 1;
        } else {
            printf("HOUR /!\\ Invalid input. Please enter a date with this format : 'hh:mm'\n\n");
        }
    } while(!isValidInput);

    isValidInput = 0;
    do {
        printf("Enter a commentary for the event (max 200 characters) \n(if your commentary lengths is inferior to 199, press enter twice\n-> : ");
        fgets(inputComment, sizeof(inputComment), stdin);
        clearInputBuffer();

        // Remove trailing newline character
        inputComment[strcspn(inputComment, "\n")] = 0;

        // check if the commentary contain the | character
        if(strchr(inputComment, '|') == NULL){
            printf("DEBUG Commentary : %s\n", inputComment);
            isValidInput = 1;
        } else {
            printf("/!\\ Invalid input. Please enter a commentary without the | character\n\n");
        }
    } while (!isValidInput);

    if(calendar->next == NULL && calendar->date == 0){
        initiateCalendar(   calendar,
                            dateIntCalendar(day, month, year),
                            hourIntCalendar(hour, minute),
                            inputComment
                            );

        printf("we initiate the calendar\n");
    } else {
        addEvent(    calendar,
                        dateIntCalendar(day, month, year),
                        hourIntCalendar(hour, minute),
                        inputComment
                    );
        printf("we add an event\n");
    }
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
    printf("\n");
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
                    "\nYou entered : %d \nEvent to suppress | %s | %s | %s\n\n",
                    selection,
                    strDate,
                    strHour,
                    eventToSuppr->commentary
                    );

            suppressEvent(calendar, eventToSuppr->date, eventToSuppr->hour);

        } else {
            printf("Invalid input. Please enter a number between 0 and %d.\n", selectionList-1);
        }
    }while(selection == -1 || selection >= selectionList);

}


char *  inputCalendarName(char * pathToCalendar){
    char input[55];

    printf("Enter the name of the calendar you want to open\n"
           "(max. length : 50 char. no whitespace and try not use prohibited character in file naming\n-> : ");
    fgets(input, sizeof(input), stdin);
    clearInputBuffer();

    if (strchr(input, ' ') != NULL) {
        printf("Invalid input. Please enter a name without whitespace.\n");
        return NULL;
    }

    // Remove trailing newline character
    input[strcspn(input, "\n")] = 0;


    char * prefix = (char *) malloc(sizeof(char) * 70);

    strcpy(prefix, "./calendar_saves/");
    strcat(prefix, input);
    strcat(prefix, ".cld");

    return prefix;
}