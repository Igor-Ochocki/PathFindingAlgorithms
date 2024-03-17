#include "weighted_linked_list.h"

node_t *getLowestWeightNode(weighted_linked_list_t **linkedListPointer)
{
    weighted_linked_list_t *linkedList = *linkedListPointer;
    if(linkedList == NULL)
        return NULL;
    if(linkedList->next == NULL)
    {
        node_t *node = linkedList->node;
        free(linkedList);
        *linkedListPointer = NULL;
        return node;
    }
    int index = 0, lvIndex = 0;
    weighted_linked_list_t *lowestValue = linkedList;
    while(linkedList != NULL)
    {
        if(linkedList->weight < lowestValue->weight)
        {
            lvIndex = index;
            lowestValue = linkedList;
        }
        linkedList = linkedList->next;
        index++;
    }
    linkedList = *linkedListPointer;
    if(lvIndex == 0)
    {
        node_t *node = linkedList->node;
        *linkedListPointer = linkedList->next;
        free(linkedList);
        return node;
    }
    while(--lvIndex)
    {
        linkedList = linkedList->next;
    }    
    linkedList->next = lowestValue->next;
    node_t *node = lowestValue->node;
    free(lowestValue);
    return node;
}

void pushWeightedLinkedList(weighted_linked_list_t **linkedListPointer, node_t *node, int weight)
{
    weighted_linked_list_t *linkedList = *linkedListPointer;
    if(linkedList == NULL)
    {
        linkedList = malloc(sizeof *linkedList);
        linkedList->node = node;
        linkedList->weight = weight;
        linkedList->next = NULL;
        *linkedListPointer = linkedList;
        return;
    }
    while(linkedList->next != NULL)
        linkedList = linkedList->next;
    weighted_linked_list_t *newListElement = malloc(sizeof *linkedList);
    newListElement->node = node;
    newListElement->weight = weight;
    newListElement->next = NULL;
    linkedList->next = newListElement;
}