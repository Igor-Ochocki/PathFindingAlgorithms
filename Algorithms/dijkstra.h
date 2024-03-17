#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_
#include "../Data/data_reader.h"
#include "../Data/maze_structure.h"
#include "../Data/weighted_linked_list.h"
/*
 * function name:       Dijkstra
 * input parameters:    
 *                      adjacencyList*  - adjacency list containing maze structure
 *                      route*          - pointer to linked list which will be used to 
 *                                        store path from startNode to targetNode
 *                      startNode*      - node in maze which is the entry point
 *                      targetNode*     - node in maze which is the target point
 * return value:        void
 * description:         This function uses Dijkstra algorithm to find the most optimal 
 *                      path from startNode to targetNode in a maze saving all subsequently 
 *                      visited nodes to route
 * 
 *                      Dijkstra Algorithm: 
 *                      Estimate weight of all nodes to be infinity, except the starting one.
 *                      After that, for each node: 
 *                          calculate distance to that node adding current distance and node's weight
 *                          if the distance is lower, save that distance as lowest to that node and put
 *                          that node to priority queue.
 *                          mark node as visited        
 *                          do the same for node with lowest weight from queue           
 */
void Dijkstra(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *startNode, node_t *targetNode);

#endif