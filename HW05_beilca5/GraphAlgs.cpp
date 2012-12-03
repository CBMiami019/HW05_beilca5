#include "GraphAlgs.h"
#include <vector>
#include <algorithm>

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
double shortestPathLength = 999999999;
double currentPathLength = 0;

//Since we will be returning a vector that is the best path, we need a variable for it
vector<NodeID> BestPath;
vector<NodeID> currentPath;

//Citation for next_permutation comes from many classmates and
//http://wordaligned.org/articles/next-permutation specifically the"Next_permutation In Action" section
/*
Next_permutation transforms the range of elements [first, last) into the lexicographically next greater
permutation of the elements. […] If such a permutation exists, next_permutation transforms [first, last)
into that permutation and returns true. Otherwise it transforms [first, last) into the lexicographically 
smallest permutation and returns false.
*/

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	//Citation:help from Adam Rasfeld in person, as well as Jake Rego, thanks for the notes!
	//Add the current graph to an array to hold the values 
	//We will be using this later to store the values of our path, in our vector BestPath
	//and call it numerous times on currentPath
	int graphSize = G->size();
	int* tempArray = new int[graphSize];
	for(int i = 0; i < graphSize; i++)
		tempArray[i] = i;
	
	do {
		double totalDistance = 0;
		// The first step that we need to take is to add up the total distance of all the nodes linked together
		//and see if that distance is greater than the current BestLength or not.
		for(int i = 0; i < graphSize; i++) {
			// Add weight between last node and first node
			if(i == graphSize-1)
				//G->weight gets the distance between the two points, from the tempArray
				totalDistance += G->weight(tempArray[i],tempArray[0]);
			// Add weight between nodes
			else
				//G->weight gets the distance between the two points, from the tempArray
				totalDistance += G->weight(tempArray[i],tempArray[i+1]);
		}
		//If this length is the best length so far, then we need to change the shortestPathLength to the current
		//distance of the bestPath. 
		if(totalDistance < shortestPathLength) {
			shortestPathLength = totalDistance;
			// Set as current best path
			for(int j = 0; j < graphSize; j++)
				BestPath[j] = tempArray[j];
		}
	/*
	Next_permutation transforms the range of elements [first, last) into the lexicographically next greater
	permutation of the elements. […] If such a permutation exists, next_permutation transforms [first, last)
	into that permutation and returns true. Otherwise it transforms [first, last) into the lexicographically 
	smallest permutation and returns false.
	*/
	} while (next_permutation(tempArray, tempArray+graphSize));

	/*Return value: Return a pair, with the first element being a vector of length n listing the 
	 *  order of the nodes in the cycle (do NOT list the start node twice), and the second element
	 *  being the length of that path
	 */
	return pair<vector<NodeID>,EdgeWeight>(BestPath,shortestPathLength);
}