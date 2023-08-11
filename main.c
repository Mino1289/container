#include <container.h>
#include <deck.h>
#include <literater.h>

int main() {
    // srand(time(NULL));
    // Container c = (Container) {.id = 321, .From = Port_of_Koper, .Dest = Port_of_Barcelona};
    // Container c1 = (Container) {.id = 322, .From = Port_of_Valencia, .Dest = Port_of_Barcelona};
    // printf("Container ID: %d\n", c.id);
    // Stack stack = stack_Init(3);
    // printf("%s\n", stack_Empty(stack) ? "vide" : "pavide");

    // stack_Push(&stack, c);
    // stack_Push(&stack, c1);
    // printf("%s\n", stack_Empty(stack) ? "vide" : "pavide");

    // Container c2 = stack_Pop(&stack);
    // printf("Container ID: %d\n", c2.id);
    // printf("%s\n", stack_Empty(stack) ? "vide" : "pavide");

    // stack_Pop(&stack);
    // printf("%s\n", stack_Empty(stack) ? "vide" : "pavide");

    const char filename[] = "test.txt";
    FILE* f = fopen(filename, "r");


    Deck deck;
    int n_dest, n_ctn;
    int* dest = NULL;
    Container* ctn = NULL;
    read_f(f, &deck, &n_dest, &n_ctn, &dest, &ctn);
    print_Deck(deck);
    
    for (int i = 0; i < n_dest; i++) {
        printf("%d ", dest[i]);
    }
    printf("\n");
    for (int i = 0; i < n_ctn; i++) {
        print_Container(ctn[i]);
    }

    fclose(f);
    free(dest);
    free(ctn);
    free_Deck(&deck);

    return 0;
}