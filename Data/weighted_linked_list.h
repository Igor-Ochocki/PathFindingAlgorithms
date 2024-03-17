#ifndef _WEIGHTED_LINKED_LIST_H_
#define _WEIGHTED_LINKED_LIST_H_
#include "maze_structure.h"

typedef struct wll {
    node_t *node;
    int weight;
    struct wll *next;
} weighted_linked_list_t;
/*
 * function name:       getLowestWeightNode
 * input parameters:    
 *                      linkedListPointer** - pointer to an address of a weighted linked list
 * return value:        node_t*             - node with lowest weight from weighted linked list
 * description:         This function returns in linear time lowest weight node that is in
 *                      provided weighted linked list and removes it from such list (sets
 *                      linkedListPointer to point to NULL).
 *                      If linkedListPointer points to NULL, it returns NULL. (linked list is empty)
 */
node_t *getLowestWeightNode(weighted_linked_list_t **linkedListPointer);
/*
 * function name:       pushWeightedLinkedList
 * input parameters:    
 *                      linkedListPointer** - pointer to an address of a weighted linked list
 *                      node_t*             - node to be added to the list
 *                      weight              - weight of a note to be added
 * return value:        void
 * description:         This function adds a new weighted node to the end of a weighted linked list
 *                      If provided with NULL, it allocates memory for new weighted linked list
 *                      and sets linkedListPOinter to point at it.
 */
void pushWeightedLinkedList(weighted_linked_list_t **linkedListPointer, node_t *node, int weight);

#endif