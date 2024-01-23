#ifndef ESSAI_T
#define ESSAI_T

typedef struct maillon {
    int date;
    int heure;
    char commentaire[200];
    struct maillon * next;
} maillon_t;

int afficherFile    (maillon_t* file);
int popFile         (maillon_t* file);
int freeFile        (maillon_t* file);
void ajoutMaillonFin   (maillon_t* file, int date, int heure, char * commentaire);
int dateStrToInt( char * date);

#endif