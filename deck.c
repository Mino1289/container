#include <deck.h>

Deck deck_create(Position size, int max) {
    Deck deck = {.length = size.row, .width = size.col};
    deck.stack = (Stack***) malloc(sizeof(Stack**)*deck.length);
    if (!deck.stack) {
        GENERROR(MALLOC_FAILED, "Could not allocate memory for the deck");
        exit(MALLOC_FAILED);
    }
    for (int i = 0; i < size.row; ++i) {
        deck.stack[i] = (Stack**) malloc(sizeof(Stack*)*deck.width);
        if (!deck.stack[i]) {
            GENERROR(MALLOC_FAILED, "Could not allocate memory for the deck[%d]", i);
            exit(MALLOC_FAILED);
        }
        for (int j = 0; j < size.col; ++j) {
            deck.stack[i][j] = stack_Init(max);
        }
    }
    return deck;
}

Stack* deck_get_At(Deck deck, Position pos) {
    return deck.stack[pos.row][pos.col];
}

DeckStackStatus deck_set_At(Deck deck, Position pos, Stack* stack) {
    Stack* tmp = deck_get_At(deck, pos);
    deck.stack[pos.row][pos.col] = stack;

    if (deck.stack[pos.row][pos.col] == tmp) {
        return STACK_SAME_SET;
    }
    if (!deck.stack[pos.row][pos.col]) {
        return STACK_EMPTY;
    }
    return STACK_ALREADY_SET;
}
