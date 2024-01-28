#ifndef ESSAI_T
#define ESSAI_T

#define MAX_VALUE_MENU 5

typedef struct calendarEvent {
    int date;
    int hour;
    char commentary[200];
    struct calendarEvent * next;
} calendarEvent;

// Calendar functions
void initiateCalendar (calendarEvent* calendar, int date, int hour, char * commentary);
void addEventEnd (calendarEvent* calendar, int date, int hour, char * commentary);
void addEvent (calendarEvent* calendar, int date, int hour, char * commentary);
calendarEvent * suppressEvent (calendarEvent* calendar, int date, int hour);
int popCalendar (calendarEvent* calendar);
int freeCalendar (calendarEvent* calendar);
calendarEvent * findEvent (calendarEvent* calendar, int selection);

//region Date functions
int dateIntCalendar (int day, int month, int year);
int cmpDate (int date1, int date2);
void dateIntToStr (int date, char * ouputStr);
int cmpDate (int date1, int date2);
//endregion

//region Hour functions
int hourIntCalendar (int hour, int minute);
int checkHourValue (int hour, int minute);
int cmpHour (int hour1, int hour2);
void hourIntToStr (int date, char * ouputStr);
//endregion

//region Save calendar functions
calendarEvent * openCalendar(char * pathNewCalendar, char * calendarPreviousName);
void saveCalendar(calendarEvent * calendar, char * pathToCalendar);
//endregion

void clearInputBuffer();

#endif