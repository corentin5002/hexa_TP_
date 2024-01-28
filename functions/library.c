#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//region Calendar functions
void initiateCalendar(calendarEvent * calendar, int date, int hour, char *commentary) {
    calendar->date = date;
    calendar->hour = hour;
    strcpy(calendar->commentary, commentary);
    calendar->next = NULL;
}

void addEventEnd(calendarEvent * calendar, int date, int hour, char *commentary) {
    calendarEvent *cursor = calendar;

    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
    calendarEvent * newMaillon = (calendarEvent *) malloc(sizeof(calendarEvent));

    newMaillon->date = date;
    newMaillon->hour = hour;
    strcpy(newMaillon->commentary, commentary);
    newMaillon->next = NULL;

    cursor->next = newMaillon;
}

void addEvent(calendarEvent * calendar, int date, int hour, char *commentary) {

    calendarEvent *cursor = calendar;
    int isFirst = 1;


    while (cursor->next != NULL) {
        printf("debug date : %d hour : %d\n", cursor->next->date, cursor->next->hour);
        if (cmpDate(cursor->next->date, date) || (cmpDate(cursor->next->date, date) && cursor->next->hour >= hour)) {
            break;
        }
        cursor = cursor->next;
        isFirst = 0;
    }

    calendarEvent * newEvent = (calendarEvent *) malloc(sizeof(calendarEvent));

    if  (isFirst &&
         cmpDate(cursor->date, date) && cursor->hour >= hour){
        //exchange of the values between the previous first event and the new one

        // Previous first event
        newEvent->date = cursor->date;
        newEvent->hour = cursor->hour;
        strcpy(newEvent->commentary, cursor->commentary);

        // New first event
        cursor -> date = date;
        cursor -> hour = hour;
        strcpy(cursor->commentary, commentary);

        newEvent->next = NULL;
        cursor->next = newEvent;

    } else {
        newEvent->date = date;
        newEvent->hour = hour;
        strcpy(newEvent->commentary, commentary);

        // Insert the new event in the calendar
        newEvent->next = cursor->next;
        cursor->next = newEvent;
    }
}

calendarEvent * suppressEvent(calendarEvent * calendar, int date, int hour) {

    int testLast = 1, testFirst = 1, findEvent = 0;
    calendarEvent *cursor = calendar;

    while (cursor->next != NULL && !findEvent) {
        //check if the date and hour are inferior to the ones of the next event
        if (cmpDate(cursor->next->date, date) && cursor->next->hour >= hour) {
            testLast = 0;
            findEvent = 1;
        } else {
            cursor = cursor->next;
            testFirst = 0;

        }
    }
    printf("DEBUG testLast : %d testFirst : %d\n", testLast, testFirst);

    calendarEvent *eventToDelete = NULL;

    if(testFirst){
        // If the event to delete is the first one
        printf("DEBUG testFirst\n");
        eventToDelete = cursor;
        calendar = cursor->next;
    }
    else if (!testLast) {
        eventToDelete = cursor->next;
        cursor->next = cursor->next->next;
    } else {
        eventToDelete = cursor->next;
        cursor->next = NULL;
    }

    printf("DEBUG  eventToDelete : %d\n", eventToDelete->date);
    free(eventToDelete);

    return calendar;
}


// return the date of the last event of the calendar
int popCalendar(calendarEvent *calendar) {
    calendarEvent *cursor = calendar;

    while (cursor->next->next != NULL) {
        cursor = cursor->next;
    }

    int valueLast = cursor->next->date;
    free(cursor->next);

    cursor->next = NULL;

    return valueLast;
}

//refaire fonction pour une non récursive


int freeCalendar(calendarEvent *calendar){
    calendarEvent * cursor = calendar;
    calendarEvent * next = calendar->next;

    while(next != NULL){
        free(cursor);
        cursor = next;
        next = next->next;
    }
    free(cursor);
    return 0;
}


calendarEvent * findEvent(calendarEvent * calendar, int selection) {
    calendarEvent *cursor = calendar;
    int selectionList = 0;

    while (cursor->next != NULL) {
        if (selectionList == selection) {
            break;
        }
        cursor = cursor->next;
        selectionList += 1;
    }

    return cursor;
}

//endregion

//region Date functions
int dateIntCalendar(int day, int month, int year){
    int date = 0;

    date = day * (int) pow(10, 6);
    date += month * (int) pow(10, 4);
    date += year;

    return date;
}

int checkDateValue(int day, int month, int year){
    int date = dateIntCalendar(day, month, year);

    int testValue = 1;
    // Maximum date value : 31/12/9999
    // Minimum date value : 01/01/1900

    if (cmpDate(1011900, date) || cmpDate(date, 31129999)) {
        printf("\nInvalid date, not include in ] 01/01/1900; 31/12/9999 [\n");
        testValue = 0;
    }

    // Check if number of day for february is valid
    else if ((month == 2) &&
             ((day < 1 || day > 28) ||
              ((day == 28) && !(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))))
            ){
        testValue = 0;
    }
    // Check if month is valid
    else if (month < 1 || month > 12){
        testValue = 0;
    }

    // Check if day is valid
    else if ((day < 1 || day > 31) &&
            (month == 1 || month == 3 || month == 5 || month == 7 ||
             month == 8 || month == 10 || month == 12)){
        testValue = 0;
    }

    else if ((day < 1 || day > 30) &&
            (month == 4 || month == 6 || month == 9 || month == 11)){
        testValue = 0;
    }

    return testValue;
}

void dateIntToStr(int date, char * ouputStr){
    char strDate[9];
    char strDateFormat[11];

    // Convert the integer to a string

    // Check if the day of the date is compose of 2 or 1 digit
    date > (int) pow(10,7) ? sprintf(strDate, "%d", date) : sprintf(strDate, "0%d", date);

    // We format the previous string to the dd/mm/yyyy format
    strncpy(strDateFormat, strDate, 2);
    strDateFormat[2] = '/';
    strncpy(&strDateFormat[3], &strDate[2], 2);
    strDateFormat[5] = '/';
    strncpy(&strDateFormat[6], &strDate[4], 4);
    strDateFormat[10] = '\0';

    // Copy of the formatted date in the pointed string
    strcpy(ouputStr, strDateFormat);
}

int cmpDate(int date1, int date2){
    // return 1 if date1 >= date2

    int day1    = date1 / (int) pow(10, 6);
    int month1  =(date1 % (int) pow(10, 6)) / (int) pow(10, 4);
    int year1   = date1 % (int) pow(10, 4);

    int day2    = date2 / (int) pow(10, 6);
    int month2  =(date2 % (int) pow(10, 6)) / (int) pow(10, 4);
    int year2   = date2 % (int) pow(10, 4);

    date1 = day1 + month1 * 100 + year1 * 10000;
    date2 = day2 + month2 * 100 + year2 * 10000;

    return date1 >= date2;
}
//endregion

//region Hour functions
int hourIntCalendar(int hour, int minute){
    int time = 0;

    time = hour * (int) pow(10, 2);
    time += minute;

    return time;
}

void hourIntToStr(int hour, char * ouputStr){
    char strHour[5];
    char strHourFormat[6];


    //checking if the hour is composed of 1 to 4 digit
    hour < 10 ?   sprintf(strHour, "000%d", hour) :
    hour < 100 ?  sprintf(strHour, "00%d", hour) :
    hour < 1000 ? sprintf(strHour, "0%d", hour) :
                  sprintf(strHour, "%d", hour);

    // We format the previous string to the hh:mm format
    strncpy(strHourFormat, strHour, 2);
    strHourFormat[2] = ':';
    strncpy(&strHourFormat[3], &strHour[2], 2);
    strHourFormat[5] = '\0';

    strcpy(ouputStr, strHourFormat);
}

int checkHourValue(int hour, int minute){
    int date = hourIntCalendar(hour, minute);
    int testValue = 1;

    // Maximum date value : 23:59
    // Minimum date value : 00:00
    if (date < 0 || date > 2359){

        testValue = 0;
    }
    // Check if number of day for february is valid
    else if ((hour < 0 || hour > 23) ||
             (minute < 0 || minute > 59)){

        testValue = 0;
    }

    return testValue;
}
//endregion

//region Save calendar functions
calendarEvent * openCalendar(char * pathNewCalendar, char * calendarPreviousName) {
    FILE *calendarSave;
    char buffer[214];

    calendarSave = fopen(pathNewCalendar, "r");

    if (calendarSave == NULL){
        printf("Error while opening the file\n");
        return NULL;
    }

    // Get name of the calendar by its path
    char * calendarName = strrchr(pathNewCalendar, '/') + 1;
    // calendarName contain "nameCalendar.cld"

    //reset of the calendar name content
    strncpy(calendarPreviousName, "", 50);
    //copy of the new name without the extension
    strncpy(calendarPreviousName, calendarName, strlen(calendarName) - 4);

    int date, hour, firstLine = 1;
    char commentary[200] = {0};
    calendarEvent * calendar = (calendarEvent *) malloc(sizeof(calendarEvent));


    //Read the file line by line to get events of the calendar
    while (fscanf(calendarSave, "%213[^\n]\n", buffer) != EOF) {
        printf("read line : %s\n", buffer);
        if(sscanf(buffer, "%d|%d|%199[^\n]", &date, &hour, commentary) == 3) {
            if (firstLine){
                initiateCalendar(calendar, date, hour, commentary);
                firstLine = 0;
            } else{
                addEventEnd(calendar, date, hour, commentary);
            }
            printf("date : %d hour : %d commentary : %s\n", date, hour, commentary);

        } else{
            printf("Something went wrong while reading the file\n");
        }
    }

    fclose(calendarSave);

    return calendar;
}

void saveCalendar(calendarEvent * calendar, char * pathToCalendar){
    FILE * calendarSave;

    calendarSave = fopen(pathToCalendar, "w");
    calendarEvent *cursor = calendar;

    if (calendarSave == NULL){
        printf("Error while opening the file\n");
        return;
    } else {
        while (cursor != NULL) {
            fprintf(calendarSave, "%d|%d|%s\n", cursor->date, cursor->hour, cursor->commentary);
            cursor = cursor->next;
        }
    }
    fclose(calendarSave);
}
//endregion

void clearInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}