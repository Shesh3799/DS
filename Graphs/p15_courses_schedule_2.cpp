#include <bits/stdc++.h>
using namespace std;

/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites 
where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be 
taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Leetcode: https://leetcode.com/problems/course-schedule-ii/description/

Approach:
Again this question is variation of Kahan's algorithms. Basically find toplogical sort for the prerequisites

Note: Only difference here is that while creating graph with prerequisite we need to take edge like
prerequisites[i][1]->prerequisites[i][0] and not prerequisites[i][0]->prerequisites[i][0] (IMP)

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

    vector<int> result;

    while(q.empty()==false){
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        for(auto x: adj[node]){
            in_degree[x]--;
            if(in_degree[x]==0)
                q.push(x);
        }
    }
    return result;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for(int i=0;i<prerequisites.size();i++){
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    vector<int> result = topo_Sort_kahns_algo(adj);

    if(result.size()==numCourses) return result;
    result.clear();


    return result;
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    // Expected Output: [0,2,1,3] or [0,1,2,3]
    vector<int> result = findOrder(numCourses, prerequisites);

    for(auto x: result){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}