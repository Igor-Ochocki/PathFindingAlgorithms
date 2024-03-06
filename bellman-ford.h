#ifndef _BELLMAN_FORD_H_
#define _BELLMAN_FORD_H_
#include "maze_structure.h"
#include "astar.h"
#include "data_reader.h"

void bellmanFordSolve(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *startNode, node_t *targetNode);

#endif