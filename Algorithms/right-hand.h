#ifndef _RIGHT_HAND_H_
#define _RIGHT_HAND_H_
#include "../Data/data_reader.h"
#include "../Data/maze_structure.h"

enum Directions {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

/*
 * function name:       isNodeInLinkedList
 * input parameters:    
 *                      linkedList*     - pointer to a linked list to be looked through
 *                      node*           - node which we want to find in a linked list
 * return value:        int             - 0 if node isn't in list, 1 if node is in list
 * description:         This function check whether node is present in a linked list
 */
int isNodeInLinkedList(linked_list_t *linkedList, node_t *node);

/*
 * function name:       getNodeFromList
 * input parameters:    
 *                      linkedList**    - pointer to an address of a linked list to be looked through
 *                      nodeToFind*     - node which we want to get from linked list
 * return value:        node_t*         - node from linked list
 * description:         This function returns element of a linked list which has same values
 *                      as the one provided in parameter, removing it from linked list, 
 *                      sets pointer of linkedList to NULL is empties list.
 *                      Returns NULL if provided pointer points to NULL
 */
node_t *getNodeFromList(linked_list_t **linkedList, node_t *nodeToFind);

/*
 * function name:       rightHandSolve
 * input parameters:    
 *                      adjacencyList*  - adjacency list containing maze structure
 *                      route*          - pointer to linked list which will be used to 
 *                                        store path from startNode to targetNode
 *                      startNode*      - node in maze which is the entry point
 *                      prevNode*       - parent of current node (initially NULL, only
 *                                        for recursive use)
 *                      targetNode*     - node in maze which is the target point
 * return value:        void
 * description:         This function uses right hand algorithm to find path from startNode to 
 *                      targetNode in a maze saving all subsequently visited nodes to route
 * 
 *                      Right Hand Algorithm: 
 *                      Upon entering maze put your "hand" on the wall and never take it away.
 *                      Move forward until the exit is found
 *                      For algorithm : 
 *                      for each <direction currently facing> (based off of width and height being constant)
 *                      try to go in order: (whichever move is eligible) (all directions are constant in a maze viewed from top)
 *                      <right>: down, right, up, left 
 *                      <left>: up, left, down, right
 *                      <up>: right, up, left, down
 *                      <down>: left, down, right, up
 */
void rightHandSolve(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *startNode, node_t *prevNode, node_t *targetNode);

#endif