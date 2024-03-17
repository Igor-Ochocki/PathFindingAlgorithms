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


/*
 * function name:       createNode
 * input parameters:    
 *                      x           - row of node
 *                      y           - column of node
 * return value:        node_t*     - struct representing node in a maze
 * description:         This function allocates memory and creates a new node
 *                      with provided values
 */
node_t *createNode(int x, int y);
/*
 * function name:       pushLinkedList
 * input parameters:    
 *                      linkedListPointer** - pointer to an address of linked list HEAD
 *                      node*               - node to be added at the end of a linked list
 * return value:        void
 * description:         This function adds provided node to the end of a linked list.
 *                      If provided with NULL, it will create a new linked list and set
 *                      linkedListPointer to point at it. 
 *                      If given NULL as a linkedList, function does nothing.
 */
void pushLinkedList(linked_list_t **linkedListPointer, node_t *node);
/*
 * function name:       reverseLinkedList
 * input parameters:    
 *                      linkedListPointer** - pointer to an address of linked list HEAD
 * return value:        void
 * description:         This function reverses linked list - so that the first element is its last
 *                      and sets linkedListPointer to point to (originally) last element of linked list.
 */
void reverseLinkedList(linked_list_t **linkedListPointer);
/*
 * function name:       popLinkedList
 * input parameters:    
 *                      linkedListPointer** - pointer to an address of linked list HEAD
 * return value:        node_t*             - last element of linked list
 * description:         This function returns last element of linked list and removes it
 *                      from the list (also frees memory allocated for the last element's
 *                      linked list representation)
 *                      Returns NULL if linked list is empty
 */
node_t *popLinkedList(linked_list_t **linkedListPointer);
/*
 * function name:       printLinkedList
 * input parameters:    
 *                      linkedList          - linked list to be printed out
 * return value:        void
 * description:         This function prints to stdout list structure containing nodes
 *                      in format "{node->x}--{node->y} "
 */
void printLinkedList(linked_list_t *linkedList);
/* ***OBSOLETE***
 * function name:       getNodeIndex
 * input parameters:    
 *                      node_t*             - node that we want to calculate index of
 * return value:        int                 - node's index in matrix
 * description:         This function calculates node's index in matrix using formula
 *                      (node->x - 1) * MAX_WIDTH + (node->y - 1)
 */
int getNodeIndex(node_t *node);
/*
 * function name:       freeAdjacencyList
 * input parameters:    
 *                      adjacencyList*      - adjacency list of a maze
 * return value:        void
 * description:         This function frees memory allocated for all linked list
 *                      elements of an adjacency list and frees memory allocated for its nodes
 */
void freeAdjacencyList(adjacency_list_t *adjacencyList);
/*
 * function name:       freeLinkedList
 * input parameters:    
 *                      linkedList*         - linked list to be freed
 * return value:        void
 * description:         This function frees memory allocated for linked list instances
 *                      !!!Doesn't free its nodes - they are freed by freeAdjacencyList!!!
 */
void freeLinkedList(linked_list_t *linkedList);


#endif