#include "data_reader.h"

adjacency_list_t *readMazeStructureFromFile(char *fileName)
{
    adjacency_list_t *adjacencyList = malloc(sizeof *adjacencyList * MAX_WIDTH * MAX_HEIGHT);
    FILE *in = fopen(fileName, "r");
    int row = 1, col, index, addIndex;
    char BUF[2049];
    char BUF2[2049];
    fgets(BUF, 2049, in);
    while(fgets(BUF, 2049, in))
    {
        col = 1;
        if(!fgets(BUF2, 2049, in))
            break;
        while(*(BUF+(col-1)*2+1) != '\0' && *(BUF+(col-1)*2+1) != '\n')
        {
            index = (row-1) * MAX_HEIGHT + (col - 1);
            node_t *currentNode = (adjacencyList+index)->node == NULL ? createNode(row, col) : (adjacencyList+index)->node;
            if((adjacencyList+index)->node == NULL)
                (adjacencyList+index)->node = currentNode;
            if(*(BUF+(col-1)*2) == ' ')
            {
                addIndex = (row-1) * MAX_HEIGHT + (col - 2);
                node_t *nodeOnLeft = (adjacencyList+addIndex)->node == NULL ? createNode(row, col - 1) : (adjacencyList+addIndex)->node;
                if((adjacencyList+addIndex)->node == NULL)
                    (adjacencyList+addIndex)->node = nodeOnLeft;
                pushLinkedList(&((adjacencyList+index)->adjacent), nodeOnLeft);
                pushLinkedList(&((adjacencyList+addIndex)->adjacent), currentNode);
            }
            if(*(BUF2+(col-1)*2+1) == ' ')
            {
                addIndex = (row) * MAX_HEIGHT + (col - 1);
                node_t *nodeBelow = (adjacencyList+addIndex)->node == NULL ? createNode(row+1, col) : (adjacencyList+addIndex)->node;
                if((adjacencyList+addIndex)->node == NULL)
                    (adjacencyList+addIndex)->node = nodeBelow;
                pushLinkedList(&((adjacencyList+index)->adjacent), nodeBelow);
                pushLinkedList(&((adjacencyList+addIndex)->adjacent), currentNode);
            }
            col++;
        }

        row++;
    }
    return adjacencyList;
}

// int main()
// {
//     adjacency_list_t *adjacencyList = readMazeStructureFromFile("maze.txt");
//     for(int i = 0; i < MAX_HEIGHT * MAX_WIDTH; i++)
//     {
//         if((adjacencyList+i)->node == NULL)
//             continue;
//         printf("%d-%d\n", (adjacencyList+i)->node->x, (adjacencyList+i)->node->y);
//         printLinkedList((adjacencyList+i)->adjacent);
//     }
// }
