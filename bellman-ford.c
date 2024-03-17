#include "dijkstra.h"
#include <limits.h>

node_t *bellmanFordSolve(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *startNode, node_t *targetNode)
{
    int dist[adjacencyList->height * adjacencyList->width];

    for(int i = 0; i < adjacencyList->height * adjacencyList->width; i++)
        dist[i] = 2e7;
    
    dist[(startNode->x - 1) * adjacencyList->width + startNode->y - 1] = 0;

    node_t *parent = malloc(sizeof *parent * adjacencyList->height * adjacencyList->width);

    for(int i = 0; i < adjacencyList->height * adjacencyList->width - 1; i++)
    {
        for(int u = 0; u < adjacencyList->height * adjacencyList->width; u++)
        {
            linked_list_t *adjacentNodes = (adjacencyList + u)->adjacent;
            node_t *curr = (adjacencyList+u)->node;
            while(adjacentNodes != NULL)
            {
                node_t *adjacent = adjacentNodes->node;
                int adjIndex = (adjacent->x - 1) * adjacencyList->width + adjacent->y - 1;
                int weight = 1;
                int currIndex = (curr->x - 1) * adjacencyList->width + curr->y - 1;

                if(dist[adjIndex] == 2e7 || dist[currIndex] + weight < dist[adjIndex])
                {
                    dist[adjIndex] = dist[currIndex] + weight;
                    *(parent+adjIndex) = *curr;
                }
                adjacentNodes = adjacentNodes->next;
            }
        }
    }

    for(int u = 0; u < adjacencyList->height * adjacencyList->width; u++)
    {
        linked_list_t *adjacentNodes = (adjacencyList + u)->adjacent;
        while(adjacentNodes != NULL)
        {
            node_t *adjacent = adjacentNodes->node;
            int adjIndex = (adjacent->x - 1) * adjacencyList->width + adjacent->y - 1;
            int weight = 1;

            if(dist[u] != 2e7 && dist[u] + weight < dist[adjIndex])
            {
                printf("Graph has negative cycle\n");
                free(parent);
                exit(0);
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
    return parent;
}

int main()
{
    adjacency_list_t *adjacencyList = readMazeStructureFromFile("150x150-0\%.txt");
    linked_list_t *route = NULL;
    node_t *node_first = createNode(1, 1);
    node_t *node_last = createNode(adjacencyList->height, adjacencyList->width);
    pushLinkedList(&route, node_first);
    node_t *parentNodes = bellmanFordSolve(adjacencyList, route, node_first, node_last);
    linked_list_t *prev = route;
    route = route->next;
    free(prev);
    reverseLinkedList(&route);
    printLinkedList(route);
    free(parentNodes);
    for(int i = adjacencyList->height * adjacencyList->width - 1; i >= 0; i--)
    {
        freeAdjacencyList((adjacencyList+i));
    }
    free(node_first);
    free(node_last);
    freeLinkedList(route);
    free(adjacencyList);
}