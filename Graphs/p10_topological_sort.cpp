#include <bits/stdc++.h>
using namespace std;

/*
Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all vertices v such that there exists a directed edge u -> v. 
Return topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v 
in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output 
will be 1 else 0

Link: https://www.geeksforgeeks.org/problems/topological-sort/1
*/

void dfs(int start,vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st){
    visited[start]=true; 
    for(auto x: adj[start]){
        if(!visited[x])
            dfs(x, adj, visited, st);
    }
    st.push(start);
    
}
    
    
// Function to return list containing vertices in Topological order.
vector<int> topologicalSort(vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    stack<int> st;
    
    for(int i=0;i<adj.size();i++){
        if(visited[i]==false)
        {
            dfs(i, adj, visited, st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
    
}


int main() {
    int V = 6;
	vector<vector<int>> adj = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	
	
	vector<int> ans = topologicalSort(adj);

	//Expected Output: 4 5 0 2 3 1
    for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;

    return 0;
}