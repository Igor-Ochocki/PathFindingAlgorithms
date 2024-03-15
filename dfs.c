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
    node_t *node_first = createNode(1,1);
    node_t *node_last = createNode(adjacencyList->height, adjacencyList->width);
    pushLinkedList(&route, node_first);
    unsigned char *visited = calloc(adjacencyList->width * adjacencyList->height, sizeof *visited);
    DFS(adjacencyList, route, visited, node_first, node_last);
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