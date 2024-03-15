#include "dfs.h"

void DFS(adjacency_list_t *adjacencyList, linked_list_t *route, unsigned char *visited, node_t *currentNode, node_t *targetNode)
{
    int currentIndex = (currentNode->x - 1) * adjacencyList->width + (currentNode->y - 1);
    int targetIndex = (targetNode->x - 1) * adjacencyList->width + (targetNode->y - 1);
    node_t *next;
    if(*(visited+currentIndex) == 1 || *(visited+targetIndex) == 1)
        return;
    *(visited+currentIndex) = 1;
    pushLinkedList(&route, currentNode);
    if(currentNode->x == targetNode->x && currentNode->y == targetNode->y)
        return;
    
    while((next = popLinkedList(&(adjacencyList+currentIndex)->adjacent)) != NULL)
    {
        DFS(adjacencyList, route, visited, next, targetNode);
        if(*(visited+targetIndex) == 1)
            return;
    }
    popLinkedList(&route);
}

int main()
{
    adjacency_list_t *adjacencyList = readMazeStructureFromFile("maze2.txt");
    linked_list_t *route = NULL;
    pushLinkedList(&route, createNode(1,1));
    unsigned char *visited = calloc(adjacencyList->width * adjacencyList->height, sizeof *visited);
    DFS(adjacencyList, route, visited, createNode(1,1), createNode(4,5));
    route = route->next;
    printLinkedList(route);
}