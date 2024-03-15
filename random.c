#include "random.h"
#include <stdio.h>
#include <time.h>

node_t *getRandomNode(linked_list_t **linkedListPointer)
{
    linked_list_t *linkedList = *linkedListPointer;
    if(linkedList == NULL)
        return NULL;
    if(linkedList->next == NULL)
        return popLinkedList(linkedListPointer);
    int size = 0;
    linked_list_t *curr = linkedList;
    while(curr != NULL)
    {
        size++;
        curr = curr->next;
    }
    int randomIndex = rand() % size;
    if(randomIndex == 0)
    {
        node_t *node = linkedList->node;
        *linkedListPointer = linkedList->next;
        free(linkedList);
        return node;
    }
    linked_list_t *prev;
    curr = linkedList;
    while(randomIndex--)
    {
        prev = curr;
        curr = curr->next;
    }
    node_t *node = curr->node;
    prev->next = curr->next;
    free(curr);
    return node;
}

void randomSolve(adjacency_list_t *adjacencyList, linked_list_t *route, unsigned char *visited, node_t *currentNode, node_t *targetNode)
{
    int currentIndex = (currentNode->x - 1) * adjacencyList->width + (currentNode->y - 1);
    int targetIndex = (targetNode->x - 1) * adjacencyList->width + (targetNode->y - 1);
    node_t *next;
    pushLinkedList(&route, currentNode);
    if(*(visited+currentIndex) == 1 || *(visited+targetIndex) == 1)
        return;
    *(visited+currentIndex) = 1;
    if(currentNode->x == targetNode->x && currentNode->y == targetNode->y)
        return;
    
    while((next = getRandomNode(&(adjacencyList+currentIndex)->adjacent)) != NULL)
    {
        randomSolve(adjacencyList, route, visited, next, targetNode);
        if(*(visited+targetIndex) == 1)
            return;
    }
}

int main()
{
    srand(time(NULL));
    adjacency_list_t *adjacencyList = readMazeStructureFromFile("maze2.txt");
    linked_list_t *route = NULL;
    node_t *node_first = createNode(1, 1);
    node_t *node_last = createNode(adjacencyList->height, adjacencyList->width);
    pushLinkedList(&route, node_first);
    unsigned char *visited = calloc(adjacencyList->height * adjacencyList->width, sizeof *visited);
    randomSolve(adjacencyList, route, visited, node_first, node_last);
    linked_list_t *prev = route;
    route = route->next;
    free(prev);
    printLinkedList(route);
    for(int i = adjacencyList->height * adjacencyList->width - 1; i >= 0; i--)
    {
        freeAdjacencyList((adjacencyList+i));
    }
    free(node_first);
    free(node_last);
    freeLinkedList(route);
    free(adjacencyList);
    free(visited);
}

// int main(){
//     srand(time(NULL));
//     linked_list_t *linkedList = NULL;
//     pushLinkedList(&linkedList, createNode(1,1));
//     pushLinkedList(&linkedList, createNode(1,2));
//     pushLinkedList(&linkedList, createNode(1,3));
//     pushLinkedList(&linkedList, createNode(1,4));
//     pushLinkedList(&linkedList, createNode(1,5));
//     pushLinkedList(&linkedList, createNode(1,6));
//     for(int i = 0; i < 6; i++)
//     {
//         getRandomNode(&linkedList);
//         printLinkedList(linkedList);
//     }
// }