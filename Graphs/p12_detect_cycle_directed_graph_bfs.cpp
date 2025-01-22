#include <bits/stdc++.h>
using namespace std;

/*
If toposort length is equal to number of nodes then cycle is not present else it is present.
This is because if the cycle is present the toposort will not be able to add all the nodes to list.
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

	if(ans.size()==V) cout<<"Cycle is not present\n";
    else cout<<"Cycle is present\n";
    

    return 0;
}