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
}

int main()
{
    adjacency_list_t *adjacencyList = readMazeStructureFromFile("maze.txt");
    linked_list_t *route = NULL;
    pushLinkedList(&route, createNode(1,1));
    BFS(adjacencyList, route, createNode(1,1), createNode(4,5));
    route = route->next;
    reverseLinkedList(&route);
    printLinkedList(route);
}

// int main()
// {
//     queue_t *queue = NULL;
//     enqueue(&queue, createNode(1,1));
//     enqueue(&queue, createNode(1,2));
//     printQueue(queue);
//     printf("---------\n");
//     enqueue(&queue, createNode(1,3));
//     printQueue(queue);
//     printf("---------\n");
//     dequeue(&queue);
//     printQueue(queue);
//     printf("---------\n");
//     dequeue(&queue);
//     printQueue(queue);
//     printf("---------\n");
//     dequeue(&queue);
//     printQueue(queue);
//     printf("%d", queue == NULL);
// }