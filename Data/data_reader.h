#ifndef _DATA_READER_H_
#define _DATA_READER_H_
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024
#include "maze_structure.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * function name:       readMazeStructureFromFile
 * input parameters:    
 *                      fileName*           - name of a file containing maze structure
 * return value:        adjacency_list_t*   - adjacency list containing maze structure,
 *                                            including its width and height
 * description:         This function reads file containing maze structure and represents
 *                      it as graph in an adjacency list.
 *                      Not secure, upon giving wrong file name or wrong file format will
 *                      throw multiple errors
 */
adjacency_list_t *readMazeStructureFromFile(char *fileName);

#endif