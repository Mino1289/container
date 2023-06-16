#include <container.h>
#include <deck.h>

int main() {
    srand(time(NULL));
    Container c = (Container) {.id = 321, .From = Port_of_Koper, .Dest = Port_of_Barcelona};
    Container c1 = (Container) {.id = 322, .From = Port_of_Valencia, .Dest = Port_of_Barcelona};
    printf("Container ID: %d\n", c.id);
    Stack stack = stack_Init();
    printf("%s\n", stack_Empty(stack) ? "vide" : "pavide");

    stack_Push(&stack, c);
    stack_Push(&stack, c1);
    printf("%s\n", stack_Empty(stack) ? "vide" : "pavide");

    Container c2 = stack_Pop(&stack);
    printf("Container ID: %d\n", c2.id);
    printf("%s\n", stack_Empty(stack) ? "vide" : "pavide");

    stack_Pop(&stack);
    printf("%s\n", stack_Empty(stack) ? "vide" : "pavide");

    return 0;
}