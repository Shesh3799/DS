#include <bits/stdc++.h>
using namespace std;

/*
You are given an Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, 
then return -1 for that vertex.

Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/0
*/

vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    int n = adj.size();
    vector<int> distance(n, INT_MAX);
    queue<int> q;
    q.push(src);
    distance[src]=0;
    while(q.empty() == false){
        int node = q.front();
        q.pop();
        for(int adj_node : adj[node]){
            int dist = distance[node] + 1;
            if(distance[adj_node]>dist){
                distance[adj_node] = dist;
                q.push(adj_node);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(distance[i]==INT_MAX) distance[i]=-1;
    }
    return distance;
}

int main() {
    int number_of_vertices = 9;
    vector<vector<int>> edges = {
        {0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}
    };
    
    int src = 0;

    vector<vector<int>> graph(number_of_vertices);

    for(auto it : edges){
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }
    cout<<"Graph is\n";
    for(int i=0;i<number_of_vertices;i++){
        cout<<i<<" --> { ";
        for(int adj_node : graph[i]){
            cout<<adj_node<<" ";
        }
        cout<<"}\n";
    }
    cout<<endl;

    vector<int> distances = shortestPath(graph, src);

    //Expected output: 0 1 2 1 2 3 3 4 4
    for(int dist : distances){
        cout<<dist<<" ";
    }
    cout<<endl;

    return 0;
}