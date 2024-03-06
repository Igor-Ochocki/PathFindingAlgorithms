#ifndef _DATA_READER_H_
#define _DATA_READER_H_
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024
#include "maze_structure.h"
#include <stdio.h>
#include <stdlib.h>

adjacency_list_t *readMazeStructureFromFile(char *fileName);

#endif