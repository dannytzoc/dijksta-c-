#include <iostream>
#include <list>
#include <utility>
#include <set>
#include <vector>
#define INF 1000000
using namespace std;
class Graph {
private:
	//number of vertices 
	int V;
	// pointer to adjaceny list 
	list<pair<int, int>>* adj;
public:
	//constructor prototype
	Graph(int);
	// method to add an edge/ weight pair 
	void addEdge(int, int, int);
	//method for shortest path 
	void shortestPath(int);

};
// constructor with the number of vertices 
Graph::Graph(int v) {
	//set number of vertices 
	V = v;
	//creates new adjacency list
	adj = new list<pair<int, int>>[v];
}
//implementtio of method add edge 
void Graph::addEdge(int v1, int v2, int weight) {
	adj[v1].push_back(make_pair(v2, weight));
}
void Graph::shortestPath(int s) {
	//create set to store vertices
	//use this to extract the shortest path 
	set < pair<int, int>> extract_set;

	//vector for distance
	//all paths are initialized to a large value
	vector <int> distances(V, INF);

	//insert the entry point into the set
	//initialize distance to 0

	extract_set.insert(make_pair(0, s));
	distances[s] = 0;

	//continue until all shortest distance are finalzied 
	while (!extract_set.empty()) {
		//extract the minimum distances
		pair<int, int>tmp = *(extract_set.begin());
		extract_set.erase(extract_set.begin());
		//get the vertex number
		int u = tmp.second;
		// go over the adjaceny list 
		for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
			//get the vertex and weight 
			int v = (*i).first;
			int weight = (*i).second;
			//check if we have found a shortes path to v
			if (distances[v] > distances[u] + weight) {
				//remove the current distance if is in the set
				if (distances[v] != INF) {
					extract_set.erase(extract_set.find(make_pair(distances[v], v)));
				}
				//update the distance 
				distances[v] = distances[u] + weight;
				extract_set.insert(make_pair(distances[v], v));

			}
		}
	}
	cout << "Minimum distance from vertex" << s << endl;
	for (int i = 0; i < V; i++) {
		cout << "Vertex" << i << "\tDistance" << distances[i] << endl;
	}

}

int main() {
	Graph g(9);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);

	g.addEdge(1, 0, 4);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);

	g.addEdge(2, 1, 8);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(2, 3, 7);

	g.addEdge(3, 2, 7);
	g.addEdge(3, 5, 14);
	g.addEdge(3, 4, 9);

	g.addEdge(4, 3, 9);
	g.addEdge(4, 5, 10);
	
	g.addEdge(5, 6, 2);
	g.addEdge(5, 2, 4);
	g.addEdge(5, 3, 14);
	g.addEdge(5, 4, 10);

	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(6, 5, 2);

	g.addEdge(7, 0, 8);
	g.addEdge(7, 1, 11);
	g.addEdge(7, 8, 7);
	g.addEdge(7, 6, 1);

	g.addEdge(8, 2, 2);
	g.addEdge(8, 7, 7);
	g.addEdge(8, 6, 6);

	g.shortestPath(0);
	return 0;
	
	
}