#ifndef __DECK_H__
#define __DECK_H__

#include <stack.h>

typedef struct Deck {
    uint8_t length, width;
    Stack*** stack; 
} Deck;

typedef struct Position {
    int row, col;
} Position;

typedef enum DeckStackStatus {
    STACK_EMPTY = (int) -1,
    STACK_SAME_SET,
    STACK_ALREADY_SET
} DeckStackStatus;

Deck deck_create(Position size);

Stack* deck_get_At(Deck deck, Position pos);

DeckStackStatus deck_set_At(Deck deck, Position pos, Stack* stack);

#endif
