#include <bits/stdc++.h>
using namespace std;
/*
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer 
in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Link: https://www.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states


Approach:
If we closely observe, all possible paths starting from a node are going to end at some terminal node unless there exists a cycle and the 
paths return back to themselves.

So, the intuition is to figure out the nodes which are neither a part of a cycle nor connected to the cycle. 
Note: Points to remember that any node which is a part of a cycle or leads to the cycle through an incoming edge towards the cycle, cannot be a safe node. 
Apart from these types of nodes, every node is a safe node.
*/

bool dfs(int start, vector<int> adj[], vector<int>& safeNodes, vector<bool>& visited, vector<bool>& pathVisited){
    //Marked visited and path visited true
    visited[start]=true;
    pathVisited[start]=true;
    
    //Check all adjacent nodes if they are safe
    for(auto x: adj[start]){
        //If node and path is visited then for sure there is a loop so it can't be safe node
        if(visited[x]==true && pathVisited[x]==true)
            return true;
        
        //If node is not visited yet then visit this node
        if(visited[x]==false){
            //If this node contains cycle then it is not a safe node so return
            if(dfs(x, adj, safeNodes, visited, pathVisited)==true){
                return true;
            } 
        }
    }
    //Remove this node from the path as recursion is complete
    pathVisited[start]=false;
    
    //The flow reached here if and only if there is no loop and we are able to reach terminal node
    //So this is a safe node
    safeNodes.push_back(start);
    return false;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<bool> pathVisited(V, false);
    vector<int> safeNodes;
    //Check for all nodes if it is a safe node or not
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            dfs(i,adj,safeNodes, visited, pathVisited);
        }
    }
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}

void validate(vector<int> expected_output, vector<int> actual_output){
    if(expected_output.size()!=actual_output.size()) {
        cout<<"Expected output size is not matching with actual"<<endl;
    }

    for(int i=0;i<expected_output.size();i++){
        if(expected_output[i]!=actual_output[i]){
            cout<<"Mismatch occured at index "<< i << " expected = " << expected_output[i] << " actual = " << actual_output[i]<<endl;
        }
    }
    cout<<"Expected and actual output is matching"<<endl;

}

int main() {
    int V = 7;
    vector<int> adj[V];
    vector<pair<int,int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3},
        {3, 0},
        {4, 5},
        {2, 5}
    };
    for(auto it:edges){
        adj[it.first].push_back(it.second);
    }

    vector<int> expected_output = {2, 4 ,5, 6};
    vector<int> actual_output = eventualSafeNodes(V,adj);

    validate(expected_output,actual_output);

       

    return 0;
}