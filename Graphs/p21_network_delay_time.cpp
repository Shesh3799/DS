#include <bits/stdc++.h>
using namespace std;

/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges 
times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to 
travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. 
If it is impossible for all the n nodes to receive the signal, return -1.

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

*/

int solve(vector<vector<pair<int,int>>>& graph, int src){
    //Min heap
    //{time, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> times(graph.size(), INT_MAX);

    pq.push({0,src});
    times[src]=0;
    
    while(pq.empty()==false){
        int time = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto& it: graph[node]){
            int new_time = time+it.second;
            if(new_time<times[it.first]){
                times[it.first]=new_time;
                pq.push({new_time, it.first});
            }
        }
    }

    int mx = times[1];
    for(int i=2;i<times.size();i++){
        mx = max(mx, times[i]);
    }
    return mx==INT_MAX?-1:mx;


}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {

    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<times.size();i++){
        graph[times[i][0]].push_back({times[i][1],{times[i][2]}});
    }
    return solve(graph,k);
    
}


int main() {
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n=4;
    int k=2;

    //Expected output 2
    cout<<networkDelayTime(times, n, k)<<endl;

    return 0;
}