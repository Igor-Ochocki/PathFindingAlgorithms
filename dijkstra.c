#include "dijkstra.h"
#include <limits.h>

void Dijkstra(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *startNode, node_t *targetNode)
{
    int dist[MAX_HEIGHT * MAX_WIDTH];
    unsigned char *visited = calloc(MAX_HEIGHT * MAX_WIDTH, sizeof *visited);

    for(int i = 0; i < MAX_HEIGHT * MAX_WIDTH; i++)
        dist[i] = INT_MAX;
    
    dist[(startNode->x - 1) * MAX_HEIGHT + startNode->y - 1] = 0;

    node_t *parent = malloc(sizeof *parent * MAX_HEIGHT * MAX_WIDTH);

    weighted_linked_list_t *wll = NULL;
    pushWeightedLinkedList(&wll, startNode, 0);

    node_t *currentNode;
    while((currentNode = getLowestWeightNode(&wll)) != NULL)
    {
        int currentIndex = (currentNode->x - 1) * MAX_HEIGHT + currentNode->y - 1;
        
        *(visited+currentIndex) = 1;

        linked_list_t *adjacentNodes = (adjacencyList+currentIndex)->adjacent;
        while(adjacentNodes != NULL)
        {
            node_t *adjacent = adjacentNodes->node;
            int adjIndex = (adjacent->x - 1) * MAX_HEIGHT + adjacent->y - 1;
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
        curr = (parent+(curr->x - 1) * MAX_HEIGHT + curr->y - 1);
    }
    pushLinkedList(&route, curr);
    return;
}

int main()
{
    adjacency_list_t *adjacencyList = readMazeStructureFromFile("maze2.txt");
    linked_list_t *route = NULL;
    pushLinkedList(&route, createNode(1,1));
    Dijkstra(adjacencyList, route, createNode(1,1), createNode(24,150));
    route = route->next;
    reverseLinkedList(&route);
    printLinkedList(route);
}