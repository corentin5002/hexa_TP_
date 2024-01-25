#ifndef UI_FUNCTIONS
#define UI_FUNCTIONS

#include "library.h"

int checkInputMenu(char * nameCalendar);
void inputEvent(/*calendarEvent * calendar*/);
void printCalendar(calendarEvent * calendar);
int checkDateValue(int day, int month, int year);
void inputSupprEvent(calendarEvent * calendar);
#endif