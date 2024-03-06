#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_
#include "data_reader.h"
#include "maze_structure.h"
#include "astar.h"

void Dijkstra(adjacency_list_t *adjacencyList, linked_list_t *linkedList, node_t *startNode, node_t *targetNode);

#endif