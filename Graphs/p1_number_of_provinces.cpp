#include <bits/stdc++.h>
using namespace std;

/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is 
connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, 
and isConnected[i][j] = 0 otherwise. 
Return the total number of provinces.

Link: https://leetcode.com/problems/number-of-provinces/description/
*/

void bfs(vector<vector<int>>& isConnected, vector<bool>& visited, int start){
    visited[start]=true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        start = q.front();
        q.pop();
        for(int i=0;i<isConnected[start].size();i++){
            if(isConnected[start][i]==1 && visited[i]==false){
                q.push(i);
                visited[i]=true;
            }
        }
    }

}

int findCircleNum(vector<vector<int>>& isConnected) {
    if(isConnected.size()==0)
        return 0;

    int count = 0;
    vector<bool> visited(isConnected.size());

    for(int i=0;i<visited.size();i++){
        if(visited[i]==false){
            count++;
            bfs(isConnected, visited, i);
        }
    }
    return count;

    
}

int main() {

    vector<vector<int>> graph = {{1,1,0},{1,1,0},{0,0,1}};
    cout<<findCircleNum(graph)<<endl;
    return 0;
}