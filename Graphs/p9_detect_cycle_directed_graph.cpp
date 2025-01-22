#include <bits/stdc++.h>
using namespace std;

/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i. 
Specifically, adj[i][j] represents an edge from vertex i to vertex j.

Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/

bool isCyclicUtil(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& path) {

    visited[node] = true;
    path[node] = true;

    // Traverse for adjacent nodes
    for (int x : adj[node]) 
    {
        //If node is already visited and is in the path
        if (visited[x]==true && path[x]) return true;

        //Do a recursion call to adjacent nodes
        else if (!visited[x])
        {
            if(isCyclicUtil(x, adj, visited, path) == true) return true;
        }
        
    }

    // Remove the vertex from recursion stack
    path[node] = false;
    return false;
}

// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<vector<int>>& adj) {
    int size = V;
    vector<bool> visited(V,false);
    vector<bool> path(V,false);
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            if(isCyclicUtil(i,adj, visited, path)) {
                cout<<"Returning true for i="<<i<<endl;
                return true;
            }
        }
    }
    return false;
}



int main() {
    int Vertex=5;
    vector<vector<int>> graph(Vertex);
    int u = 3, v= 0;
    graph[u].push_back(v);
    u=4, v=2;
    graph[u].push_back(v);
    u=1, v=2;
    graph[u].push_back(v);
    cout<<isCyclic(Vertex, graph);
    return 0;
}

