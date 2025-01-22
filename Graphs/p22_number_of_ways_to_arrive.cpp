#include <bits/stdc++.h>
using namespace std;

/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. 
The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between 
any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi 
that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the 
shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

*/

int solve(int n, vector<vector<pair<int,int>>>& graph, int src, int dst){
    typedef pair<int,pair<int,int>> PIII;

    //{level, {node, distance}}
    queue<PIII> q;

    vector<int> distances(n,INT_MAX);

    q.push({0,{src,0}});
    distances[src]=0;

    int min_distance = INT_MAX;
    int count = 0;

    while(q.empty()==false){
        int level = q.front().first;
        int node = q.front().second.first;
        int dist = q.front().second.second;

        q.pop();

        for(auto& it: graph[node]){
            int new_dist = dist+it.second;
            if(distances[it.first]>=new_dist){
                distances[it.first]=new_dist;
                q.push({level+1,{it.first,new_dist}});
                if(it.first == dst && min_distance>new_dist){
                    min_distance=new_dist;
                    count=1;
                }
                else if(it.first == dst && min_distance==new_dist){
                    count++;
                }
            }
            
        }
    }
    return count;
}

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int,int>>> graph(n);
    for(int i=0;i<roads.size();i++){
        graph[roads[i][0]].push_back({roads[i][1],{roads[i][2]}});
    }
    return solve(n,graph,0,n-1);
}

int main() {
    int n = 7;
    vector<vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};

    cout<<countPaths(n, roads)<<endl;

    return 0;
}