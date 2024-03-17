#include "astar.h"

void AStar(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *startNode, node_t *targetNode)
{
    int heuristicValue = abs(startNode->x - targetNode->x) + abs(startNode->y - targetNode->y);
    weighted_linked_list_t *wll = NULL;
    pushWeightedLinkedList(&wll, startNode, heuristicValue);
    unsigned char *visited = calloc(adjacencyList->height * adjacencyList->width, sizeof *visited);
    int targetIndex = (targetNode->x - 1) * adjacencyList->width + (targetNode->y - 1);
    node_t *parent = malloc(sizeof *parent * adjacencyList->height * adjacencyList->width);
    int *srcDest = calloc(adjacencyList->height * adjacencyList->width, sizeof *srcDest);
    node_t *curr, *next;

    while((curr = getLowestWeightNode(&wll)) != NULL)
    {
        int currentIndex = (curr->x - 1) * adjacencyList->width + (curr->y - 1);
        *(visited+currentIndex) = 1;
        if(*(visited+targetIndex) == 1)
            continue;
        while((next = popLinkedList(&(adjacencyList+currentIndex)->adjacent)) != NULL)
        {
            if(*(visited + (next->x - 1) * adjacencyList->width + next->y - 1) == 1)
                continue;
            if(next->x == targetNode->x && next->y == targetNode->y)
                *(visited+targetIndex) = 1;
            heuristicValue = abs(next->x - targetNode->x) + abs(next->y - targetNode->y);
            pushWeightedLinkedList(&wll, next, heuristicValue + *(srcDest+currentIndex) + 1);
            *(parent + (next->x - 1) * adjacencyList->width + next->y - 1) = *curr;
            *(srcDest + (next->x - 1) * adjacencyList->width + next->y - 1) = *(srcDest+currentIndex) + 1;
        }
    }
    curr = targetNode;
    while(curr->x != startNode->x || curr->y != startNode->y)
    {
        pushLinkedList(&route, curr);
        curr = (parent+(curr->x - 1) * adjacencyList->width + curr->y - 1);
    }
    pushLinkedList(&route, curr);
    free(visited);
    free(parent);
    free(srcDest);
    return;
}

int main()
{
    adjacency_list_t *adjacencyList = readMazeStructureFromFile("./TestCases/maze2.txt");
    linked_list_t *route = NULL;
    node_t *node_first = createNode(1, 1);
    node_t *node_last = createNode(adjacencyList->height, adjacencyList->width);
    pushLinkedList(&route, node_first);
    AStar(adjacencyList, route, node_first, node_last);
    linked_list_t *prev = route;
    route = route->next;
    free(prev);
    reverseLinkedList(&route);
    printLinkedList(route);
    for(int i = adjacencyList->height * adjacencyList->width - 1; i >= 0; i--)
    {
        freeAdjacencyList((adjacencyList+i));
    }
    free(node_first);
    free(node_last);
    freeLinkedList(route);
    free(adjacencyList);
}
