#include <bits/stdc++.h>
using namespace std;

/*
You are given N nodes labelled from 0 to N - 1 and a list of undirected edges( each edge is a pair of nodes). Your task is to find out if these edges make a valid tree. If they make a valid tree return true, else return false.

Tree is a special graph. It has the following properties.

• It is connected
• It has no cycle.

Link: https://www.naukri.com/code360/problems/graph-valid-tree_1376618?leftPanelTabValue=PROBLEM
*/

bool checkLoop(vector<vector<int>>& graph, int node, int parent, vector<bool>& visited){
    visited[node]=true;
    //Visit adjacent nodes
    for(auto adjNode : graph[node]){
        if(visited[adjNode]==true && adjNode!=parent){
            return true;
        }
        
        if(visited[adjNode] == false){
            if(checkLoop(graph, adjNode, node, visited)==true) return true;
        }
    }
    return false;
}
bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    for(const auto& it : edges){
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }
    bool isLoopExist = checkLoop(graph, 0, -1, visited);
    
    bool isConnected = true;
    for(bool status : visited){
        if(status==false){
            isConnected=false;
            break;
        }
    }
    //If loop doesn't exist and all the nodes are connected then it is a valid tree
    return !isLoopExist && isConnected;
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    int n=5;
    int m= 5;
    cout<<checkgraph(edges, n, m)<<endl;

    

    return 0;
}