#ifndef _ASTAR_H_
#define _ASTAR_H_
#include "data_reader.h"
#include "maze_structure.h"

typedef struct wll {
    node_t *node;
    int weight;
    struct wll *next;
} weighted_linked_list_t;

node_t *getLowestWeightNode(weighted_linked_list_t **linkedListPointer);
void pushWeightedLinkedList(weighted_linked_list_t **linkedListPointer, node_t *node, int weight);
void AStar(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *startNode, node_t *targetNode);

#endif