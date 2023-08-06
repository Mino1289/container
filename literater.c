#include <literater.h>

void read_f(FILE* f, int* n_dest, int* n_ctn, int** dest, Container** ctn) {
    if (!f) {
        GENERROR(FILE_ERROR, "File pointer is NULL");
        exit(FILE_ERROR);
    }
    fscanf(f, "%d\n", n_dest);
    *dest = (int*) malloc(*n_dest*sizeof(int));
    if (!*dest) {
        GENERROR(MALLOC_FAILED, "Memory allocation failed");
    }
    for (int i = 0; i < *n_dest; i++) {
        fscanf(f, "%d;", &((*dest)[i]));
    }
    
    fscanf(f, "%d", n_ctn);
    *ctn = (Container*) malloc((*n_ctn)*sizeof(Container));
    if (!ctn) {
        GENERROR(MALLOC_FAILED, "Memory allocation failed");
    }
    for (int i = 0; i < *n_ctn; i++) {
        fscanf(f, "%d;%d;%d", &((*ctn)[i].id), &((*ctn)[i].From), &((*ctn)[i].Dest));
    }
}