#include "dijkstra.h"
#include <limits.h>

void Dijkstra(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *startNode, node_t *targetNode)
{
    int dist[adjacencyList->height * adjacencyList->width];
    unsigned char *visited = calloc(adjacencyList->height * adjacencyList->width, sizeof *visited);

    for(int i = 0; i < adjacencyList->height * adjacencyList->width; i++)
        dist[i] = INT_MAX;
    
    dist[(startNode->x - 1) * adjacencyList->width + startNode->y - 1] = 0;

    node_t *parent = malloc(sizeof *parent * adjacencyList->height * adjacencyList->width);

    weighted_linked_list_t *wll = NULL;
    pushWeightedLinkedList(&wll, startNode, 0);

    node_t *currentNode;
    while((currentNode = getLowestWeightNode(&wll)) != NULL)
    {
        int currentIndex = (currentNode->x - 1) * adjacencyList->width + currentNode->y - 1;
        
        *(visited+currentIndex) = 1;

        linked_list_t *adjacentNodes = (adjacencyList+currentIndex)->adjacent;
        while(adjacentNodes != NULL)
        {
            node_t *adjacent = adjacentNodes->node;
            int adjIndex = (adjacent->x - 1) * adjacencyList->width + adjacent->y - 1;
            if(*(visited+adjIndex) != 1)
            {
                int newDistance = dist[currentIndex] + 1;
                if(newDistance < dist[adjIndex])
                {
                    dist[adjIndex] = newDistance;
                    *(parent + adjIndex) = *currentNode;
                    pushWeightedLinkedList(&wll, adjacent, newDistance);
                }
            }
            adjacentNodes = adjacentNodes->next;
        }
    }
    node_t *curr = targetNode;
    while(curr->x != startNode->x || curr->y != startNode->y)
    {
        pushLinkedList(&route, curr);
        curr = (parent+(curr->x - 1) * adjacencyList->width + curr->y - 1);
    }
    pushLinkedList(&route, curr);
    free(parent);
    free(visited);
    return;
}

int main()
{
    adjacency_list_t *adjacencyList = readMazeStructureFromFile("./TestCases/maze2.txt");
    linked_list_t *route = NULL;
    node_t *node_first = createNode(1, 1);
    node_t *node_last = createNode(adjacencyList->height, adjacencyList->width);
    pushLinkedList(&route, node_first);
    Dijkstra(adjacencyList, route, node_first, node_last);
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