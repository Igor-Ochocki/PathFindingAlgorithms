#ifndef _MAZE_STRUCTURE_H_
#define _MAZE_STRUCTURE_H_
#include <stdlib.h>

typedef struct n {
    int x;
    int y;
} node_t;

typedef struct ll {
    struct n *node;
    struct ll *next;
} linked_list_t;

typedef struct aj {
    struct n *node;
    struct ll *adjacent;
    int width;
    int height;
} adjacency_list_t;

node_t *createNode(int x, int y);
void pushLinkedList(linked_list_t **linkedListPointer, node_t *node);
void reverseLinkedList(linked_list_t **linkedListPointer);
node_t *popLinkedList(linked_list_t **linkedListPointer);
void printLinkedList(linked_list_t *linkedList);
int getNodeIndex(node_t *node);


#endif