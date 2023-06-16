#ifndef __STACK_H__
#define __STACK_H__

#include <container.h>


typedef struct Stack {
    Container* ctn;
    int top;
} Stack;

Stack stack_Init();

bool stack_Empty(Stack stack);

int stack_Size(Stack stack);

void stack_Push(Stack* stack, Container container);

Container stack_Pop(Stack* stack);



#endif
