// solution to this problem (found here: https://pastebin.com/DQpNGQwA)
/*Problem:
    Wandering Thonker Problem
 
Description:
    The Thonker is on a journey to thonk at all cities on his list and to do this he must visit all of them at least once.
    Help him find the best route to take on this journey.
 
Input:
    Connections available to use in travel.
    Array consisting of arrays of 3 elements. First two elements are names of cities and third is the cost to travel from the first city to the second one.
Output:
    Total cost of cheapest route to visit all cities at least once.
    An integer.
 
Details:
    There is always at least one connection to and from each city.
    You can only travel using the connections.
    Costs to travel between cities are not necessarily symmetric.
    Journey may be started from any city
 
Example input:
    [["City1", "City2", 100], ["City1", "City3", 30], ["City2", "City3" 150], ["City3", "City1", 15]]
Example output:
    115
 
Extra:
    Include the route to take in output*/

#include <unordered_map>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>

void preProcessEdges(	std::vector<std::tuple<std::string, std::string, unsigned int>> & edgeSet,
						std::vector<std::string> & vertexSet,
						std::unordered_map<std::string, std::vector<std::pair<std::string, unsigned int>>> & outGoingEdges) {

	// get all of the vertices
	for (int i = 0; i < edgeSet.size(); ++i) {
		auto newVertex = std::get<0>(edgeSet[i]);
		if (std::find(vertexSet.begin(), vertexSet.end(), newVertex) == vertexSet.end()) {
			vertexSet.push_back(newVertex);
		}
		newVertex = std::get<1>(edgeSet[i]);
		if (std::find(vertexSet.begin(), vertexSet.end(), newVertex) == vertexSet.end()) {
			vertexSet.push_back(newVertex);
		}
	}

	// initialize vectors of outgoing edges from each vertex
	for (auto x : vertexSet) {
		outGoingEdges[x] = std::vector<std::pair<std::string, unsigned int>>();
	}

	// get all of the outgoing edges from each vertex
	for (int i = 0; i < edgeSet.size(); ++i) {

		auto whichVertex = std::get<0>(edgeSet[i]);
		auto targetVertex = std::get<1>(edgeSet[i]);
		auto edgeWeight = std::get<2>(edgeSet[i]);
		outGoingEdges[whichVertex].push_back(std::pair<std::string, unsigned int>(targetVertex, edgeWeight));
	}


}

// quick and dirty recursive backtracking TSP
unsigned int TSP(	unsigned int sum,
					unsigned int & bonusPathSum,
					unsigned int depthSinceLastNewNode,
					std::string & whichVertex,
					std::vector<std::string> & thePath,
					std::vector<std::string> & bonusPath,
					std::vector<std::string> & vertexSet,
					std::unordered_map<std::string, std::vector<std::pair<std::string, unsigned int>>> & outGoingEdges) {

	// break any cycles that don't add new nodes
	if (depthSinceLastNewNode >= vertexSet.size()) {
		return UINT_MAX;
	}

	// if we've seen all of the nodes then we return the sum
	// bruteforce :)
	bool isAtLeastHamiltonian = true;
	for (auto x : vertexSet) {
		if (std::find(thePath.begin(), thePath.end(), x) == thePath.end()) {
			isAtLeastHamiltonian = false;
		}
	}
	if (isAtLeastHamiltonian) {

		// compare sum of bonus path
		// to new completed path and exchange it
		// if the new path is shorter
		if (sum < bonusPathSum) {
			bonusPath.clear();
			for (auto x : thePath) {
				bonusPath.push_back(x);
			}
			bonusPathSum = sum;
		}

		return sum;
	}
	
	// run TSP on all of the outgoing edges
	// and take the best answer
	auto min = UINT_MAX;
	for (auto x : outGoingEdges[whichVertex]) {

		// add a new node
		unsigned int newDepth = depthSinceLastNewNode + 1;
		if (std::find(thePath.begin(), thePath.end(), x.first) == thePath.end()) {
			newDepth = 0;
		}
		thePath.push_back(x.first);

		auto y = TSP(sum + x.second, bonusPathSum, newDepth, x.first, thePath, bonusPath, vertexSet, outGoingEdges);
		thePath.pop_back();
		if (y < min) {
			min = y;
		}
	}
	
	return min;

}

int main() {

	// generate the edge set
	auto theEdgeSet = std::vector<std::tuple<std::string, std::string, unsigned int>>();
	theEdgeSet.emplace_back("a", "b", 1);
	theEdgeSet.emplace_back("b", "a", 1);
	theEdgeSet.emplace_back("b", "c", 1);
	theEdgeSet.emplace_back("c", "b", 1);
	theEdgeSet.emplace_back("c", "d", 2);
	theEdgeSet.emplace_back("d", "e", 1);
	theEdgeSet.emplace_back("e", "c", 1);
	theEdgeSet.emplace_back("e", "f", 10);
	theEdgeSet.emplace_back("f", "b", 1);
	theEdgeSet.emplace_back("a", "f", 5);
	
	auto theVertexSet = std::vector<std::string>();
	auto theOutGoingEdges = std::unordered_map<std::string, std::vector<std::pair<std::string, unsigned int>>>();

	preProcessEdges(theEdgeSet, theVertexSet, theOutGoingEdges);

	auto bonusPath = std::vector<std::string>();

	// run TSP from any city
	auto thePath = std::vector<std::string>();
	auto min = UINT_MAX;
	auto bonusPathSum = UINT_MAX;
	for (int i = 0; i < theVertexSet.size(); ++i) {
		thePath.push_back(theVertexSet[i]);
		auto x = TSP(0, bonusPathSum, 0, theVertexSet[i], thePath, bonusPath, theVertexSet, theOutGoingEdges);
		thePath.pop_back();
		if (x < min) {
			min = x;

		}
	}

	std::cout << min << std::endl;

	// print bonus path
	for (auto x : bonusPath) {
		std::cout << x << std::endl;
	}
	
	std::cin.get();

	return 0;
}