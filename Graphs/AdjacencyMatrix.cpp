#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int numberOfVertices;
    vector<vector<int>> graph;
    bool directed;
    public:
    Graph(int numberOfVertices, bool isDirected = false){
        this->numberOfVertices = numberOfVertices;
        this->directed = isDirected;
        graph.resize(numberOfVertices);
        for(int i=0;i<numberOfVertices;i++){
            graph[i].resize(numberOfVertices, 0);
        }
    }

    void addEdge(int src, int dest){
        graph[src][dest] = 1;
        if(!directed){
            graph[dest][src] = 1;
        }
    }

    void printGraph(){
         // Iterate through each vertex
        for (int i = 0; i < numberOfVertices; ++i) {
            // Print the vertex
            cout << i << ": ";
            // Iterate through the adjacency list of the vertex
            for (int j = 0; j < numberOfVertices; ++j) {
                if(graph[i][j]==1){
                    // Print each adjacent vertex
                    cout << j << " -> ";
                }
            }
            // Indicate the end of the adjacency list
            cout << "NULL" << endl;
        }
    }
};


int main() {
    // Number of vertices in the graph
    int vertices = 3;

    // Undirected Graph Example
    Graph undirectedGraph(vertices);
    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(0, 2);
    undirectedGraph.addEdge(1, 2);

    // Print the adjacency list of the undirected graph
    cout << "Undirected Graph Adjacency Matrix:" << endl;
    undirectedGraph.printGraph();

    cout << endl;

    // Directed Graph Example
    Graph directedGraph(vertices, true);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(1, 0);
    directedGraph.addEdge(2, 0);

    // Print the adjacency list of the directed graph
    cout << "Directed Graph Adjacency Matrix:" << endl;
    directedGraph.printGraph();

    return 0;
}