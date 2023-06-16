#include <stack.h>

Stack stack_Init() {
    return (Stack) {.ctn = NULL, .top = 0};
}

bool stack_Empty(Stack stack) {
    return (stack_Size(stack) <= 0);
}

int stack_Size(Stack stack) {
    return stack.top;
}

void stack_Push(Stack* stack, Container container) {
    if (stack_Empty(*stack)) {
        stack->top = 1;
        stack->ctn = (Container*) malloc(sizeof(Container));
    } else {
        stack->ctn = (Container*) realloc(stack->ctn, (stack->top++)*sizeof(Container));
    }
    stack->ctn[stack_Size(*stack)-1] = container;
}

Container stack_Pop(Stack* stack) {
    if (stack_Empty(*stack)) {
        GENERROR(EMPTY_STACK, "Trying to remove an element from an empty stack");
        exit(EMPTY_STACK);
        return NULLContainer;
    }
    Container element = stack->ctn[--stack->top];
    if (!stack_Empty(*stack)) {
        stack->ctn = (Container*) realloc(stack->ctn, stack_Size(*stack)*sizeof(Container));
    } else {
        free(stack->ctn);
        stack->ctn = NULL;
    }
    return element;
}
