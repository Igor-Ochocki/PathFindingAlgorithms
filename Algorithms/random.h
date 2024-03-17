#ifndef _RANDOM_H_
#define _RANDOM_H_
#include "../Data/data_reader.h"
#include "../Data/maze_structure.h"
#include <stdlib.h>

/*
 * function name:       getRandomNode
 * input parameters:    
 *                      linkedList**    - pointer to an address of linked list head
 * return value:        node_t*         - randomly selected node from linked list
 * description:         This function returns randomly selected node from the linked list
 *                      given as paremeter and removes it from list. In case selected node
 *                      is the last one, it sets pointer of linkedList to NULL and returns
 *                      NULL if given pointer is NULL
 */
node_t *getRandomNode(linked_list_t **linkedList);

/*
 * function name:       randomSolve
 * input parameters:    
 *                      adjacencyList*  - adjacency list containing maze structure
 *                      route*          - pointer to linked list which will be used to 
 *                                        store path from startNode to targetNode
 *                      visited*        - array representing whether node has been visited
 *                                        initially filled with 0's
 *                      currentNode*    - node in maze which is the entry point
 *                      targetNode*     - node in maze which is the target point
 * return value:        void
 * description:         This function uses random algorithm to find path from startNode to 
 *                      targetNode in a maze saving all subsequently visited nodes to route
 * 
 *                      Random Algorithm: 
 *                      For each node select random surrounding node and repeat until target
 *                      node is found        
 */
void randomSolve(adjacency_list_t *adjacencyList, linked_list_t *route, unsigned char *visited, node_t *startNode, node_t *targetNode);

#endif