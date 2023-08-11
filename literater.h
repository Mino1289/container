#ifndef __LITERATER_H__
#define __LITERATER_H__

#include <deck.h>

/**
 * @brief Read a file and return a Container array
 * 
 * The file must be in the following format:
 * 
 * 1st line: the size of the deck (length and width) and the max height of the stack separated by ; (semicolon) 
 *      *(the deck is always a rectangle, the "max height" is the number of container that we can put on top of each other)
 * 2nd line: number of destinations (ports) the ship will visit
 * 3rd line: ID of the ports the ship will visit separated by ; (semicolon)
 * 4th line: number of containers
 * The next lines are the containers, each line is a container, in the following format:
 * ID;From;Dest
 * 
 * @param f FILE* – the file pointer
 * @param deck Deck* – A pointer on the deck
 * @param n_dest int* – A pointer on the number of destinations
 * @param n_ctn int* – A pointer on the number of containers
 * @param dest int** – A pointer on a list of destinations
 * @param ctn Container** – A pointer on a list of containers
 */
void read_f(FILE* f, Deck *deck, int *n_dest, int *n_ctn, int* *dest, Container* *ctn);

#endif