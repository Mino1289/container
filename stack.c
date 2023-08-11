#include <stack.h>

Stack* stack_Init(int max) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (!stack) {
        GENERROR(MALLOC_FAILED, "Could not allocate memory for the stack");
        exit(MALLOC_FAILED);
    }
    stack->ctn = NULL;
    stack->top = 0;
    stack->max = max;
    return stack;
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
    } else if (stack-> top > stack->max) {
        stack->ctn = (Container*) realloc(stack->ctn, (stack->top++)*sizeof(Container));
    } else {
        GENERROR(FULL_STACK, "Trying to push an element to a full stack");
        exit(FULL_STACK);
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
