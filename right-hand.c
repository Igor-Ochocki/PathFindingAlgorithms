#include "right-hand.h"
#include <stdio.h>

int isNodeInLinkedList(linked_list_t *linkedList, node_t *node)
{
    if(linkedList == NULL)
        return 0;
    while(linkedList != NULL)
    {
        if(linkedList->node->x == node->x && linkedList->node->y == node->y)
            return 1;
        linkedList = linkedList->next;
    }
    return 0;
}
node_t *getNodeFromList(linked_list_t **linkedListPointer, node_t *nodeToFind)
{
    linked_list_t *linkedList = *linkedListPointer;
    if(linkedList == NULL)
        return NULL;
    while(!(linkedList->node->x == nodeToFind->x && linkedList->node->y == nodeToFind->y))
        linkedList = linkedList->next;
    return linkedList->node;
}

void rightHandSolve(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *currentNode, node_t *prevNode, node_t *targetNode)
{
    pushLinkedList(&route, currentNode);
    if(currentNode->x == targetNode->x && currentNode->y == targetNode->y)
    {
        linked_list_t *prev = route;
        route = route->next;
        free(prev);
        printLinkedList(route);
        freeLinkedList(route);
        return;
    }
    int currentIndex = (currentNode->x - 1) * adjacencyList->width + currentNode->y - 1;
    enum Directions dir;
    if(prevNode == NULL)
        dir = DOWN;
    else
    {
        if(currentNode->x == prevNode->x)
        {
            if(currentNode->y > prevNode->y)
                dir = RIGHT;
            else
                dir = LEFT;
        }
        else
        {
            if(currentNode->x > prevNode->x)
                dir = DOWN;
            else
                dir = UP;
        }
    }
    
    node_t *nodeUp = createNode(currentNode->x - 1, currentNode->y);
    node_t *nodeRight = createNode(currentNode->x, currentNode->y + 1);
    node_t *nodeDown = createNode(currentNode->x + 1, currentNode->y);
    node_t *nodeLeft = createNode(currentNode->x, currentNode->y-1);
    node_t *nodes[4][4] = {{nodeRight, nodeUp, nodeLeft, nodeDown}, {nodeDown, nodeRight, nodeUp, nodeLeft}, {nodeLeft, nodeDown, nodeRight, nodeUp}, {nodeUp, nodeLeft, nodeDown, nodeRight}};
    for(int i = 0; i < 4; i++)
    {
        if(isNodeInLinkedList((adjacencyList+currentIndex)->adjacent, nodes[dir][i]))
        {
            node_t *curr = createNode(nodes[dir][i]->x, nodes[dir][i]->y);
            rightHandSolve(adjacencyList, route, curr, currentNode, targetNode);
            free(curr);
            break;
        }
    }
    free(nodeUp);
    free(nodeRight);
    free(nodeDown);
    free(nodeLeft);
}

int main()
{
    adjacency_list_t *adjacencyList = readMazeStructureFromFile("maze2.txt");
    linked_list_t *route = NULL;
    node_t *node_first = createNode(1, 1);
    node_t *node_last = createNode(adjacencyList->height, adjacencyList->width);
    pushLinkedList(&route, node_first);
    rightHandSolve(adjacencyList, route, node_first, NULL, node_last);
    for(int i = adjacencyList->height * adjacencyList->width - 1; i >= 0; i--)
    {
        freeAdjacencyList((adjacencyList+i));
    }
    free(node_first);
    free(node_last);
    free(adjacencyList);
    return 0;
}