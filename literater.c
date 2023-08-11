#include <literater.h>

void read_f(FILE* f, Deck *deck, int *n_dest, int *n_ctn, int* *dest, Container* *ctn) {
    if (!f) {
        GENERROR(FILE_ERROR, "File pointer is NULL");
        exit(FILE_ERROR);
    }
    int max;
    fscanf(f, "%hhu;%hhu;%d\n", &(deck->length), &(deck->width), &max);
    if (!deck->length || !deck->width || !max) {
        GENERROR(FILE_ERROR, "Deck size is 0");
        exit(FILE_ERROR);
    }
    Deck tmp = deck_create((Position){.row = deck->length, .col = deck->width}, max);
    *deck = tmp;
    fscanf(f, "%d\n", n_dest);
    if (!*n_dest) {
        GENERROR(FILE_ERROR, "Number of destinations is 0");
        exit(FILE_ERROR);
    }
    *dest = (int*) malloc(*n_dest*sizeof(int));
    if (!*dest) {
        GENERROR(MALLOC_FAILED, "Memory allocation failed");
    }
    for (int i = 0; i < *n_dest; i++) {
        fscanf(f, "%d;", &((*dest)[i]));
    }
    
    fscanf(f, "%d", n_ctn);
    if (!*n_ctn) {
        GENERROR(FILE_ERROR, "Number of containers is 0");
        exit(FILE_ERROR);
    }
    *ctn = (Container*) malloc((*n_ctn)*sizeof(Container));
    if (!ctn) {
        GENERROR(MALLOC_FAILED, "Memory allocation failed");
    }
    for (int i = 0; i < *n_ctn; i++) {
        fscanf(f, "%d;%d;%d", &((*ctn)[i].id), &((*ctn)[i].From), &((*ctn)[i].Dest));
    }
}