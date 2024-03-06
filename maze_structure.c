#include "maze_structure.h"
#include <stdio.h>

node_t *createNode(int x, int y)
{
    node_t *newNode = malloc(sizeof *newNode);
    newNode->x = x;
    newNode->y = y;
    return newNode;
}

void pushLinkedList(linked_list_t **linkedListPointer, node_t *node)
{
    linked_list_t *linkedList = *linkedListPointer;
    if(linkedList == NULL)
    {
        linkedList = malloc(sizeof *linkedList);
        linkedList->node = node;
        linkedList->next = NULL;
        *linkedListPointer = linkedList;
        return;
    }
    while(linkedList->next != NULL)
        linkedList = linkedList->next;
    linked_list_t *newListElement = malloc(sizeof *newListElement);
    newListElement->node = node;
    newListElement->next = NULL;
    linkedList->next = newListElement;
}

node_t *popLinkedList(linked_list_t **linkedListPointer)
{
    linked_list_t *linkedList = *linkedListPointer;
    if(linkedList == NULL)
        return NULL;
    if(linkedList->next == NULL)
    {
        node_t *node = linkedList->node;
        free(linkedList);
        (*linkedListPointer) = NULL;
        return node;
    }
    int index = 0;
    while(linkedList->next != NULL)
    {
        linkedList = linkedList->next;
        index++;
    }
    node_t *node = linkedList->node;
    free(linkedList);
    linkedList = *linkedListPointer;
    while(--index)
        linkedList = linkedList->next;
    linkedList->next = NULL;
    return node;
}

void reverseLinkedList(linked_list_t **linkedListPointer)
{
    linked_list_t *current = *linkedListPointer;
    if(current == NULL || current->next == NULL)
        return;
    linked_list_t *next = NULL, *prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *linkedListPointer = prev;
}

void printLinkedList(linked_list_t *linkedList)
{
    while(linkedList != NULL)
    {
        printf("%d-%d -- ", linkedList->node->x, linkedList->node->y);
        linkedList = linkedList->next;
    }
    printf("\n");
}

int getNodeIndex(node_t *node)
{
    return ((node->x - 1) * 1024 + (node->y - 1));
}