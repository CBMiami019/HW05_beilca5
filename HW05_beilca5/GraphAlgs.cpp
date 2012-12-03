#include "GraphAlgs.h"
#include <vector>

using namespace std;

/*
 * Solves the Traveling Salesperson Problem: finding the shortest cycle through a graph that 
 * vists every node exactly once (with exception of the first node, which is repeated as the 
 * last node in the cycle.)
 * 
 * Return value: Return a pair, with the first element being a vector of length n listing the 
 *  order of the nodes in the cycle (do NOT list the start node twice), and the second element
 *  being the length of that path (do NOT forget to include the edge from the last node back to
 *  the start node in the total length.
 *
 * Preconditions: 
 *     G is undirected.
 *     Every pair of nodes u,v  (u != v) has an edge connecting the of weight > 0.
 */

//Trying to use the notes taken in class to make this algorithm work

//We need a few variables to make this work
double shortestPathLength = 0;
double currentPathLength = 0;

//Since we will be returning a vector that is the best path, we need a variable for it
vector<NodeID> BestPath;
vector<NodeID> currentPath;

//Citation for next_permutation comes from many classmates and
//http://wordaligned.org/articles/next-permutation specifically the"Next_permutation In Action" section

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	for(int i = 1; i < G->size(); i++)
		currentPath.push_back(i);

	
}