#include <bits/stdc++.h>
using namespace std;

/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Link: https://leetcode.com/problems/course-schedule/

Approach:
This is variation of Kahan's Algorithm. Basically if we can have a topological sort then yes we can finish else we can't :)

*/

int topo_Sort_kahns_algo(vector<vector<int>>& adj){
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
    
    int cnt=0;
    
    while(q.empty()==false){
        int node = q.front();
        q.pop();
        cnt++;
        
        for(auto x: adj[node]){
            in_degree[x]--;
            if(in_degree[x]==0)
                q.push(x);
        }
    }
    return cnt;    
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for(int i=0;i<prerequisites.size();i++){
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }

    if(topo_Sort_kahns_algo(adj)==numCourses) return true;
    return false;

}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites= {{1,0},{2,1},{3,2}};
    //Expected answer True;
    cout<<canFinish(numCourses, prerequisites)<<endl;
    
    numCourses = 5;
    vector<vector<int>> prerequisites1= {{1,2},{4,3},{2,4},{4,1}};
    //Expected answer False;
    cout<<canFinish(numCourses, prerequisites1)<<endl;
    return 0;
}