#ifndef _BFS_H_
#define _BFS_H_
#include "../Data/data_reader.h"
#include "../Data/maze_structure.h"

typedef struct q {
    node_t *node;
    struct q *next;
} queue_t;

/*
 * function name:       dequeue
 * input parameters:    
 *                      queue_t**   - pointer to an address of queue head
 * return value:        node_t*     - node at the beggining of queue
 * description:         This function takes pointer to an address of queue head
 *                      and returns first element of this queue, in case there
 *                      is no element it returns NULL. Function also correctly
 *                      empties queue and changes to what queuePointer points to
 *                      so that the queue is being emptied
 */
node_t *dequeue(queue_t **queuePointer);

/*
 * function name:       enqueue
 * input parameters:    
 *                      queuePointer**  - pointer to an address of queue head
 *                      node_t*         - node to be added to the end of queue
 * return value:        void
 * description:         This function takes pointer to an address of queue head
 *                      and adds a new node to the end of it. In case the queue
 *                      is empty, it allocated the memory needed for it and sets
 *                      queuePointer to point at the newly created queue.
 */
void enqueue(queue_t **queuePointer, node_t *node);

/*
 * function name:       BFS
 * input parameters:    
 *                      adjacencyList*  - adjacency list containing maze structure
 *                      route*          - pointer to linked list which will be used to 
 *                                        store path from startNode to targetNode
 *                      startNode*      - node in maze which is the entry point
 *                      targetNode*     - node in maze which is the target point
 * return value:        void
 * description:         This function uses BFS algorithm to find path from startNode 
 *                      to targetNode in a maze saving all subsequently visited nodes to route
 *                      
 *                      BFS Algorithm:
 *                      Starting from start node, for each other node:
 *                          add all surrounding nodes to queue
 *                          until queue is clear or target is found: take node from queue
 */
void BFS(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *startNode, node_t *targetNode);

#endif