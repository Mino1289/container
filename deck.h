#ifndef __DECK_H__
#define __DECK_H__

#include <stack.h>

typedef struct Deck {
    uint8_t length, width;
    Stack*** stack; 
} Deck;

typedef struct Position {
    uint8_t row, col;
} Position;

typedef enum DeckStackStatus {
    STACK_EMPTY = (int) -1,
    STACK_SAME_SET,
    STACK_ALREADY_SET
} DeckStackStatus;

Deck deck_create(Position size, int max);

Stack* deck_get_At(Deck deck, Position pos);

DeckStackStatus deck_set_At(Deck deck, Position pos, Stack* stack);

void print_Deck(Deck deck);

void free_Deck(Deck *deck);

#endif
