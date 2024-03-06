#ifndef _RIGHT_HAND_H_
#define _RIGHT_HAND_H_
#include "data_reader.h"
#include "maze_structure.h"

enum Directions {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};
int isNodeInLinkedList(linked_list_t *linkedList, node_t *node);
node_t *getNodeFromList(linked_list_t **linkedList, node_t *nodeToFind);
void rightHandSolve(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *startNode, node_t *prevNode, node_t *targetNode);

#endif