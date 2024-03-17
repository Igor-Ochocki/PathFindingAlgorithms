#ifndef _ASTAR_H_
#define _ASTAR_H_
#include "../Data/data_reader.h"
#include "../Data/maze_structure.h"
#include "../Data/weighted_linked_list.h"

/*
 * function name:       AStar
 * input parameters:    
 *                      adjacencyList*  - adjacency list containing maze structure
 *                      route*          - pointer to linked list which will be used to 
 *                                        store path from startNode to targetNode
 *                      startNode*      - node in maze which is the entry point
 *                      targetNode*     - node in maze which is the target point
 * return value:        void
 * description:         This function uses AStar algorithm and Manhattan heuristic function
 *                      to find the most optimal path from startNode to targetNode in a maze
 *                      saving all subsequently visited nodes to route
 * 
 *                      AStar algorithm : 
 *                      start from a node, add all surrounding nodes to queue with weights 
 *                      as follows : f(n) + h(n)
 *                          where f(n) is a distance to the node from startNode
 *                          and h(n) is a heuristic value (Manhattan) distance from the node 
 *                          calculated as follows: 
 *                          dist = abs(node.x - target.x) + abs(node.y - target.y)
 *                      Repeat until queue is clear or the target node is found selecting always
 *                      node with the lowest weight
 */
void AStar(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *startNode, node_t *targetNode);

#endif