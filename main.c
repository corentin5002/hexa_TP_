#include <stdio.h>
#include <stdlib.h>
#include "./library.h"
#include "./functions/UI_functions.h"


int main(int argc , char ** argv)
{
    calendarEvent * file = (calendarEvent *) malloc(sizeof(calendarEvent));

    int date = 12122012;
    for (int heure = 1200; heure < 1260; ++heure) {

        ajoutMaillonFin(file, date, heure, "TEST : Commentaire");
        printf("heure : %d\n", heure);
    }
//    afficherFile(file);

//    dateStrToInt("12e05/8492");

//    checkInputMenu("Aventure_en_mordor");
    showCalendar(file);

    freeFile(file);

    return 0;
}
