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
        return;
    int currentIndex = (currentNode->x - 1) * 1024 + currentNode->y - 1;
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
            break;
        }
    }
}

int main()
{
    adjacency_list_t *adjacencyList = readMazeStructureFromFile("maze.txt");
    linked_list_t *route = NULL;
    pushLinkedList(&route, createNode(1,1));
    rightHandSolve(adjacencyList, route, createNode(1,1), NULL, createNode(4,5));
    route = route->next;
    printLinkedList(route);
    return 0;
}