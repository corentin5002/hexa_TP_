#ifndef UI_FUNCTIONS
#define UI_FUNCTIONS

#include "library.h"

int inputMenu(char * nameCalendar);
void inputEvent(calendarEvent * calendar);
void printCalendar(calendarEvent * calendar);
int checkDateValue(int day, int month, int year);
calendarEvent * inputSupprEvent(calendarEvent * calendar);
char * inputCalendarName();
#endif