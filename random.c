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
    int currentIndex = (currentNode->x - 1) * MAX_HEIGHT + (currentNode->y - 1);
    int targetIndex = (targetNode->x - 1) * MAX_HEIGHT + (targetNode->y - 1);
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
    adjacency_list_t *adjacencyList = readMazeStructureFromFile("maze.txt");
    linked_list_t *route = NULL;
    pushLinkedList(&route, createNode(1,1));
    unsigned char *visited = calloc(MAX_HEIGHT * MAX_WIDTH, sizeof *visited);
    randomSolve(adjacencyList, route, visited, createNode(1,1), createNode(4,5));
    route = route->next;
    printLinkedList(route);
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