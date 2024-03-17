#ifndef _DFS_H_
#define _DFS_H_
#include "../Data/data_reader.h"
#include "../Data/maze_structure.h"

/*
 * function name:       DFS
 * input parameters:    
 *                      adjacencyList*  - adjacency list containing maze structure
 *                      route*          - pointer to linked list which will be used to 
 *                                        store path from startNode to targetNode
 *                      visited*        - array representing whether node has been visited
 *                                        initially filled with 0's
 *                      currentNode*      - node in maze which is the entry point
 *                      targetNode*     - node in maze which is the target point
 * return value:        void
 * description:         This function uses DFS algorithm to find recursively path 
 *                      from startNode to targetNode in a maze saving all subsequently 
 *                      visited nodes to route
 *                      
 *                      DFS Algorithm:
 *                      Starting from start node, mark node as visited, for each unvisited
 *                      node surrounding the node, perform DFS for that node.
 */
void DFS(adjacency_list_t *adjacencyList, linked_list_t *route, unsigned char *visited, node_t *currentNode, node_t *targetNode);

#endif