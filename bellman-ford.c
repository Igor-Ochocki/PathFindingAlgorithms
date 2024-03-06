#include "dijkstra.h"
#include <limits.h>

void bellmanFordSolve(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *startNode, node_t *targetNode)
{
    int dist[MAX_HEIGHT * MAX_WIDTH];

    for(int i = 0; i < MAX_HEIGHT * MAX_WIDTH; i++)
        dist[i] = 2e7;
    
    dist[(startNode->x - 1) * MAX_HEIGHT + startNode->y - 1] = 0;

    node_t *parent = malloc(sizeof *parent * MAX_HEIGHT * MAX_WIDTH);

    for(int i = 0; i < MAX_HEIGHT * MAX_WIDTH - 1; i++)
    {
        for(int u = 0; u < MAX_HEIGHT * MAX_WIDTH; u++)
        {
            linked_list_t *adjacentNodes = (adjacencyList + u)->adjacent;
            node_t *curr = (adjacencyList+u)->node;
            while(adjacentNodes != NULL)
            {
                node_t *adjacent = adjacentNodes->node;
                int adjIndex = (adjacent->x - 1) * MAX_HEIGHT + adjacent->y - 1;
                int weight = 1;
                int currIndex = (curr->x - 1) * MAX_HEIGHT + curr->y - 1;

                if(dist[adjIndex] == 2e7 || dist[currIndex] + weight < dist[adjIndex])
                {
                    dist[adjIndex] = dist[currIndex] + weight;
                    *(parent+adjIndex) = *curr;
                }
                adjacentNodes = adjacentNodes->next;
            }
        }
    }

    for(int u = 0; u < MAX_HEIGHT * MAX_WIDTH; u++)
    {
        linked_list_t *adjacentNodes = (adjacencyList + u)->adjacent;
        while(adjacentNodes != NULL)
        {
            node_t *adjacent = adjacentNodes->node;
            int adjIndex = (adjacent->x - 1) * MAX_HEIGHT + adjacent->y - 1;
            int weight = 1;

            if(dist[u] != 2e7 && dist[u] + weight < dist[adjIndex])
            {
                printf("Graph has negative cycle\n");
                exit(0);
            }
            adjacentNodes = adjacentNodes->next;
        }
    }

    node_t *curr = targetNode;
    while(curr->x != startNode->x || curr->y != startNode->y)
    {
        pushLinkedList(&route, curr);
        curr = (parent+(curr->x - 1) * MAX_HEIGHT + curr->y - 1);
    }
    pushLinkedList(&route, curr);
    return;
}

int main()
{
    adjacency_list_t *adjacencyList = readMazeStructureFromFile("maze.txt");
    linked_list_t *route = NULL;
    pushLinkedList(&route, createNode(1,1));
    bellmanFordSolve(adjacencyList, route, createNode(1,1), createNode(4,5));
    route = route->next;
    reverseLinkedList(&route);
    printLinkedList(route);
}