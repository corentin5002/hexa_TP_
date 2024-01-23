#include <stdio.h>
#include <malloc.h>
#include "./library.h"



int main(int argc , char ** argv)
{
    maillon_t * file = (maillon_t *) malloc(sizeof(maillon_t));

    int date = 12122012;
    for (int heure = 1200; heure < 1260; ++heure) {

//        ajoutMaillonFin(file, date, heure, "TEST : Commentaire");
        printf("heure : %d\n", heure);
    }
//    afficherFile(file);
    freeFile(file);

    dateStrToInt("12e05/8492");

    return 0;
}
