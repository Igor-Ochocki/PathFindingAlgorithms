#ifndef _BFS_H_
#define _BFS_H_
#include "maze_structure.h"
#include "data_reader.h"

typedef struct q {
    node_t *node;
    struct q *next;
} queue_t;

node_t *dequeue(queue_t **queuePointer);
void enqueue(queue_t **queuePointer, node_t *node);
void BFS(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *startNode, node_t *targetNode);

#endif