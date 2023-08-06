#include <container.h>

void print_Container(Container c) {
    printf("Container @%p\n", (void*) &c);
    printf("\tID: %d\n", c.id);
    printf("\tFrom: %d\n", c.From);
    printf("\tDest: %d\n", c.Dest);
}