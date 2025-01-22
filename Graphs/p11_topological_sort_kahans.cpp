#include <bits/stdc++.h>
using namespace std;

/*
Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all vertices v such that there exists a directed edge u -> v. 
Return topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, 
vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct 
then the output will be 1 else 0.

The algorithm steps are as follows:

First, we will calculate the indegree of each node and store it in the indegree array. We can iterate through the given adj list, 
and simply for every node u->v, we can increase the indegree of v by 1 in the indegree array. 

Initially, there will be always at least a single node whose indegree is 0. So, we will push the node(s) with indegree 0 into the queue.

Then, we will pop a node from the queue including the node in our answer array, and for all its adjacent nodes, we will decrease the 
indegree of that node by one. For example, if node u that has been popped out from the queue has an edge towards node v(u->v), 
we will decrease indegree[v] by 1.

After that, if for any node the indegree becomes 0, we will push that node again into the queue.
We will repeat steps 3 and 4 until the queue is completely empty. Finally, completing the BFS we will get the linear ordering of the 
nodes in the answer array.
*/

vector<int> topo_Sort_kahns_algo(vector<vector<int>>& adj){
    int v = adj.size();
    vector<int> in_degree(adj.size(), 0);
    
    for(int i=0; i<v;i++){
        for(auto x: adj[i]){
        in_degree[x]++;   
        }
    }
    
    queue<int> q;
    for(int i=0;i<v;i++){
        if(in_degree[i]==0)
            q.push(i);
    }
    
    vector<int> ans;
    
    while(q.empty()==false){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto x: adj[node]){
            in_degree[x]--;
            if(in_degree[x]==0)
                q.push(x);
        }
    }
    return ans;
}


int main() {
    int V = 6;
	vector<vector<int>> adj = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	
	
	vector<int> ans = topo_Sort_kahns_algo(adj);

	//Expected Output: 4 5 0 2 3 1
    for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;

}