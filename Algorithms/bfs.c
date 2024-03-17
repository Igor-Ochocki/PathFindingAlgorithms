#include "bfs.h"

node_t *dequeue(queue_t **queuePointer)
{
    queue_t *queue = *queuePointer;
    if(queue == NULL)
        return NULL;
    if(queue->next == NULL)
    {
        node_t *node = queue->node;
        free(queue);
        *queuePointer = NULL;
        return node;
    }
    node_t *node = queue->node;
    *queuePointer = queue->next;
    free(queue);
    return node;
}

void enqueue(queue_t **queuePointer, node_t *node)
{
    queue_t *queue = *queuePointer;
    if(queue == NULL)
    {
        queue = malloc(sizeof *queue);
        queue->node = node;
        queue->next = NULL;
        *queuePointer = queue;
        return;
    }
    while(queue->next != NULL)
        queue = queue->next;
    queue_t *newQueue = malloc(sizeof *newQueue);
    newQueue->node = node;
    newQueue->next = NULL;
    queue->next = newQueue;
}

void printQueue(queue_t *queue)
{
    while(queue != NULL)
    {
        printf("%d-%d --> ", queue->node->x, queue->node->y);
        queue = queue->next;
    }
    printf("\n");
}

void BFS(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *startNode, node_t *targetNode)
{
    queue_t *queue = NULL;
    enqueue(&queue, startNode);
    unsigned char *visited = calloc(adjacencyList->height * adjacencyList->width, sizeof *visited);
    int targetIndex = (targetNode->x - 1) * adjacencyList->width + (targetNode->y - 1);
    node_t *parent = malloc(sizeof *parent * adjacencyList->height * adjacencyList->width);
    node_t *curr, *next;

    while((curr = dequeue(&queue)) != NULL)
    {
        int currentIndex = (curr->x - 1) * adjacencyList->width + (curr->y - 1);
        *(visited+currentIndex) = 1;
        if(*(visited+targetIndex) == 1)
            continue;
        
        while((next = popLinkedList(&(adjacencyList+currentIndex)->adjacent)) != NULL)
        {
            if(*(visited + (next->x - 1) * adjacencyList->width + next->y - 1) == 1)
                continue;
            enqueue(&queue, next);
            *(parent + (next->x - 1) * adjacencyList->width + next->y - 1) = *curr;
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
}

int main()
{
    adjacency_list_t *adjacencyList = readMazeStructureFromFile("./TestCases/maze2.txt");
    linked_list_t *route = NULL;
    node_t *node_first = createNode(1, 1);
    node_t *node_last = createNode(adjacencyList->height, adjacencyList->width);
    pushLinkedList(&route, node_first);
    BFS(adjacencyList, route, node_first, node_last);
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