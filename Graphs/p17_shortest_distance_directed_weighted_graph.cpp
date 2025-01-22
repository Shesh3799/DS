#include <bits/stdc++.h>
using namespace std;

/*
Given a DAG, find the shortest path from the source to all other nodes in this DAG. In this problem statement, we have assumed the source vertex to be ‘0’. 
You will be given the weighted edges of the graph.

There are 3 ways to implement it
1. Normal djisktra's algorith
2. Using topo sort for DAG using priority queue (Pending)
3. Using topo sort for DAG using set (Pending)

Input: n = 6, m= 7
edges =[[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]

Output: 0 2 3 6 1 5

Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/0

*/

vector<int> shortestPath(vector<vector<pair<int,int>>>& adj, int src) {
    int n = adj.size();
    vector<int> distance(n, INT_MAX);
    queue<int> q;
    q.push(src);
    distance[src]=0;
    while(q.empty() == false){
        int node = q.front();
        q.pop();
        for(auto adj_node : adj[node]){
            int dist = distance[node] + adj_node.second;
            if(distance[adj_node.first]>dist){
                distance[adj_node.first] = dist;
                q.push(adj_node.first);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(distance[i]==INT_MAX) distance[i]=-1;
    }
    return distance;
}
    
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> graph(V);
    for(auto it : edges){
        graph[it[0]].push_back({it[1], it[2]});
    }
    
    return shortestPath(graph, 0);
    
}

int main() {

    int vertices = 6, edges= 7;
    vector<vector<int>> edges_list ={{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
    
    vector<int> distances = shortestPath(vertices, edges, edges_list);

    //Expected output: 0 2 3 6 1 5
    for(int dist : distances){
        cout<<dist<<" ";
    }
    cout<<endl;
    return 0;
}