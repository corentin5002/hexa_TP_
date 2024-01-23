#ifndef ESSAI_T
#define ESSAI_T

#define MAX_VALUE_MENU 5

typedef struct calendarEvent {
    int date;
    int heure;
    char commentaire[200];
    struct calendarEvent * next;
} calendarEvent;

int afficherFile    (calendarEvent* file);
int popFile         (calendarEvent* file);
int freeFile        (calendarEvent* file);
void ajoutMaillonFin   (calendarEvent* file, int date, int heure, char * commentaire);
int dateStrToInt( char * date);
#endif