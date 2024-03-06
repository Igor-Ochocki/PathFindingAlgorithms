#ifndef _DFS_H_
#define _DFS_H_
#include "maze_structure.h"
#include "data_reader.h"

void DFS(adjacency_list_t *adjacencyList, linked_list_t *route, unsigned char *visited, node_t *currentNode, node_t *targetNode);

#endif