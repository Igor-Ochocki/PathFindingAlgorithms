#ifndef _RANDOM_H_
#define _RANDOM_H_
#include "data_reader.h"
#include "maze_structure.h"
#include <stdlib.h>

node_t *getRandomNode(linked_list_t **linkedList);
void randomSolve(adjacency_list_t *adjacencyList, linked_list_t *route, unsigned char *visited, node_t *currentNode, node_t *targetNode);

#endif