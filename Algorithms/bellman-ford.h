#ifndef _BELLMAN_FORD_H_
#define _BELLMAN_FORD_H_
#include "../Data/weighted_linked_list.h"
#include "../Data/data_reader.h"
#include "../Data/maze_structure.h"

/*
 * function name:       bellmanFordSolve
 * input parameters:    
 *                      adjacencyList*  - adjacency list containing maze structure
 *                      route*          - pointer to linked list which will be used to 
 *                                        store path from startNode to targetNode
 *                      startNode*      - node in maze which is the entry point
 *                      targetNode*     - node in maze which is the target point
 * return value:        node_t*         - pointer to list of parents, required to be freed
 *                                        later on to avoid memory leaks
 * description:         This function uses Bellman-Ford algorithm to find the most optimal 
 *                      path from startNode to targetNode in a maze saving all subsequently 
 *                      visited nodes to route
 * 
 *                      Bellman-ford Algorithm: 
 *                      Estimate weight of all nodes to be infinity, except the starting one.
 *                      After that, relax all nodes V*E times, where V is number of vertices
 *                      and E is number of edges (in our maze it is its width * height).
 *                      Next, during each relaxation correct all cells to have the lowest possible weight
 *                      - either their weight or distance from other cell that has lesser weight
 *                      After all relaxations are done, relax graph once again. If relaxation is possible,
 *                      then there is a negative cycle and algorithms is insufficient to find shortest path.                     
 */
node_t *bellmanFordSolve(adjacency_list_t *adjacencyList, linked_list_t *route, node_t *startNode, node_t *targetNode);

#endif