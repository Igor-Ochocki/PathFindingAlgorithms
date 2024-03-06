#include "astar.h"

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

void printWeightedLinkedList(weighted_linked_list_t *linkedList)
{
    while(linkedList != NULL)
    {
        printf("%d-%d@%d --> ", linkedList->node->x, linkedList->node->y, linkedList->weight);
        linkedList = linkedList->next;
    }
    printf("\n");
}

void AStar(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *startNode, node_t *targetNode)
{
    int heuristicValue = abs(startNode->x - targetNode->x) + abs(startNode->y - targetNode->y);
    weighted_linked_list_t *wll = NULL;
    pushWeightedLinkedList(&wll, startNode, heuristicValue);
    unsigned char *visited = calloc(MAX_HEIGHT * MAX_WIDTH, sizeof *visited);
    int targetIndex = (targetNode->x - 1) * MAX_HEIGHT + (targetNode->y - 1);
    node_t *parent = malloc(sizeof *parent * MAX_HEIGHT * MAX_WIDTH);
    int *srcDest = calloc(MAX_HEIGHT * MAX_WIDTH, sizeof *srcDest);
    node_t *curr, *next;

    while((curr = getLowestWeightNode(&wll)) != NULL)
    {
        int currentIndex = (curr->x - 1) * MAX_HEIGHT + (curr->y - 1);
        *(visited+currentIndex) = 1;
        if(*(visited+targetIndex) == 1)
            continue;
        while((next = popLinkedList(&(adjacencyList+currentIndex)->adjacent)) != NULL)
        {
            if(*(visited + (next->x - 1) * MAX_HEIGHT + next->y - 1) == 1)
                continue;
            if(next->x == targetNode->x && next->y == targetNode->y)
                *(visited+targetIndex) = 1;
            heuristicValue = abs(next->x - targetNode->x) + abs(next->y - targetNode->y);
            pushWeightedLinkedList(&wll, next, heuristicValue + *(srcDest+currentIndex) + 1);
            *(parent + (next->x - 1) * MAX_HEIGHT + next->y - 1) = *curr;
            *(srcDest + (next->x - 1) * MAX_HEIGHT + next->y - 1) = *(srcDest+currentIndex) + 1;
        }
    }
    curr = targetNode;
    while(curr->x != startNode->x || curr->y != startNode->y)
    {
        pushLinkedList(&route, curr);
        curr = (parent+(curr->x - 1) * MAX_HEIGHT + curr->y - 1);
    }
    pushLinkedList(&route, curr);
    return;
}

// int main()
// {
//     adjacency_list_t *adjacencyList = readMazeStructureFromFile("maze2.txt");
//     linked_list_t *route = NULL;
//     pushLinkedList(&route, createNode(1,1));
//     AStar(adjacencyList, route, createNode(1,1), createNode(24,150));
//     route = route->next;
//     reverseLinkedList(&route);
//     printLinkedList(route);
// }

// int main()
// {
//     weighted_linked_list_t *linkedList = NULL;
//     pushWeightedLinkedList(&linkedList, createNode(1,1), 4);
//     pushWeightedLinkedList(&linkedList, createNode(1,2), 6);
//     pushWeightedLinkedList(&linkedList, createNode(1,3), 1);
//     pushWeightedLinkedList(&linkedList, createNode(1,5), 5);
//     for(int i = 0; i < 5; i++)
//     {
//         printWeightedLinkedList(linkedList);
//         getLowestWeightNode(&linkedList);
//     }

// }