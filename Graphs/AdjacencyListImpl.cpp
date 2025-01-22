#include <bits/stdc++.h>
using namespace std;

class Graph
{
    vector<vector<int>> adjList;
    bool isDirected;
    public:
    Graph(int vertices, bool directed = false)
    {
        // Resize the adjacency list to accommodate the vertices
        adjList.resize(vertices);
        // Set the directed flag
        isDirected = directed;
    }

    void addEdge(int src, int dest)
    {
        // Add the destination to the adjacency list of the source
        adjList[src].push_back(dest);
        // If the graph is undirected
        if (!isDirected) {
            // Add the source to the adjacency list of the destination
            adjList[dest].push_back(src);
        }
    }

    void printGraph()
    {
        // Iterate through each vertex
        for (int i = 0; i < adjList.size(); ++i) {
            // Print the vertex
            cout << i << ": ";
            // Iterate through the adjacency list of the vertex
            for (int j = 0; j < adjList[i].size(); ++j) {
                // Print each adjacent vertex
                cout << adjList[i][j] << " -> ";
            }
            // Indicate the end of the adjacency list
            cout << "NULL" << endl;
        }
    }

};

int main()
{
    // Number of vertices in the graph
    int vertices = 3;

    // Undirected Graph Example
    Graph undirectedGraph(vertices);
    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(0, 2);
    undirectedGraph.addEdge(1, 2);

    // Print the adjacency list of the undirected graph
    cout << "Undirected Graph Adjacency List:" << endl;
    undirectedGraph.printGraph();

    cout << endl;

    // Directed Graph Example
    Graph directedGraph(vertices, true);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(1, 0);
    directedGraph.addEdge(2, 0);

    // Print the adjacency list of the directed graph
    cout << "Directed Graph Adjacency List:" << endl;
    directedGraph.printGraph();

    return 0;
}