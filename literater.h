#ifndef __LITERATER_H__
#define __LITERATER_H__

#include <container.h>

/**
 * @brief Read a file and return a Container array
 * 
 * The file must be in the following format:
 * 
 * 1st line: number of destinations (ports) the ship will visit
 * 2nd line: ID of the ports the ship will visit separated by ; (semicolon)
 * 3rd line: number of containers
 * The next lines are the containers, each line is a container, in the following format:
 * ID;From;Dest
 * 
 * @param f 
 * @return Container*
 */
void read_f(FILE* f, int* n_dest, int* n_ctn, int** dest, Container** ctn);

#endif