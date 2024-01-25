#include <stdio.h>
#include <stdlib.h>
#include "functions/library.h"
#include "./functions/UI_functions.h"


int main(int argc , char ** argv)
{
//    calendarEvent * calendar = (calendarEvent *) malloc(sizeof(calendarEvent));
//
//    int date = 25022024;
//    int hour = 1825;
//    char commentary[200] = "Bonjour la plèbe";
//    calendar->next = NULL;
//
//    initiateCalendar(calendar, date, hour, commentary);
//    addEventEnd(calendar, 26022024, 1730, "Rendu TP");
//    addEventEnd(calendar, 12042024, 1730, "Se branler");
//    addEventEnd(calendar, 12042024, 1735, "Se nettoyer");
//
//    addEvent(calendar, 12042024, 1700 , "Prendre des mouchoirs");
//    suppressEvent(calendar, 12042024, 1730);
//
//    printf("\n\n");
//    printCalendar(calendar);
//
////    checkInputMenu("Aventure_en_mordor");
//
//    inputSupprEvent(calendar);
//
//    freeCalendar(calendar);


    openCalendar("./calendar_saves/rencontreEnPapouasie.cld");


//    inputEvent();
//    int i = dateIntCalendar(12, 01, 2024);
//
//    char * str = (char *) malloc(sizeof(char) * 11);
//
//
//    printf("Date is valid %s\n", checkDateValue(28, 02, 1900) ? "true" : "false");
//    dateIntToStr(i, str);
//    printf("date %s\n", str);
//
//
//    int time = hourIntCalendar(12, 30);
//    printf("time : %d\n", time);
//    char * strHour = (char *) malloc(sizeof(char) * 6);
//    hourIntToStr(time, strHour);
//    printf("test %s\n", strHour);



//    free(strHour);
//    free(str);
    return 0;
}
