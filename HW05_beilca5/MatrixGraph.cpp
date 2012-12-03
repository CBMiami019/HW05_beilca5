#include <vector>
#include "MatrixGraph.h"

using namespace std;

//Constructor
MatrixGraph::MatrixGraph(unsigned num_nodes){
	num_edges = 0;
	M.resize(num_nodes, std::vector<EdgeWeight>(num_nodes, 0.0));
}

//Deconstructor
MatrixGraph::~MatrixGraph(){
}

//Modifier
 /*
   * Add a *weighted*, *undirected* edge between nodes u and v.
   * 
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
   *     u != v
   *     There is no edge between u and v.
   *     weight > 0
   */
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	//Check that all the preconditions were met
	if(0 <= u < M.size() && 0 <= v < M.size() && u !=v && weight > 0){
		//**Still possibly have to check that there is no existing edge between u and v??
		M[u][v] = weight;
		M[v][u] = weight;
	}
}

//Inspector
 /*
   * Get the weight between nodes u and v; return 0 if there is no edge.
   *
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
   */
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	//Check that the preconditions are met, and return 0 if one is not met
	if(u < 0.0 || v < 0.0 || u > M.size() || v > M.size())
		return 0.0;
	else
		//If the preconditions are met, then return the weight of that edge
		return M[u][v];
}

//Inspector
 /*
   * Return a list of NodeID/EdgeWeight pairs describing the nodes adjacent to edge w.
   *
   * Preconditions: u is a legal label.
   */
std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	//Counter Variable for the list
	int counter;
	//This list will store the pairs of edges adjacent to NodeID u inside of a for loop
	std::list<NWPair> Pairs;
	std::vector<EdgeWeight>::const_iterator start;
	for(start = M[u].begin(); start != M[u].end(); start++) {
		//Check if the weight of the pointer is anything greater than 0
		//Meaning there is an adjacent node
		if (*start != 0.0){
			//Need a counter variable so they don't get assigned the same starting value
			Pairs.push_front(NWPair(counter, *start));
			counter++;
		}
	}
	return Pairs;
}

//Inspector
/*
   * Return the degree (i.e. the number of neighbors) of node u.
   *
   * Preconditions: u is a legal label;
   */
unsigned MatrixGraph::degree(NodeID u) const{
	//Very similar to the getAdj method, but we don't need a counter since we're not returning pairs, just a number
	unsigned numNeighbors = 0;
	std::vector<EdgeWeight>::const_iterator start;
	for(start = M[u].begin(); start != M[u].end(); start++){
		//Again if the pointer is greater than 0, then there is a node
		if(*start != 0){
			numNeighbors++;
		}
	}
	return numNeighbors;
}

//Inspector
/*
   * Return the number of nodes in the graph.
   */
unsigned MatrixGraph::size() const{
	return M.size();
}

//Inspector
  /* 
   * Return the number of edges in the graph.
   */
unsigned MatrixGraph::numEdges() const{
	return num_edges;
}