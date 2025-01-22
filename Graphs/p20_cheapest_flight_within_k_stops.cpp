#include <bits/stdc++.h>
using namespace std;

/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates 
that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 
If there is no such route, return -1.

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700

The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

*/

int solve(int n, vector<vector<pair<int,int>>>& graph, int src, int dst, int k){
    typedef pair<int,pair<int,int>> PIII;

    //{stops, {node, price}}
    queue<PIII> q;

    vector<int> prices(n,INT_MAX);

    q.push({0,{src,0}});
    prices[src]=0;

    while(q.empty()==false){
        int stops = q.front().first;
        int node = q.front().second.first;
        int price = q.front().second.second;

        q.pop();

        for(auto& it: graph[node]){
            int new_price = price+it.second;
            if(stops<=k && prices[it.first]>new_price){
                prices[it.first]=new_price;
                q.push({stops+1,{it.first,new_price}});
            }
            
        }
    }
    return prices[dst]==INT_MAX?-1:prices[dst];
}
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

    vector<vector<pair<int,int>>> graph(n);
    for(int i=0;i<flights.size();i++){
        graph[flights[i][0]].push_back({flights[i][1],{flights[i][2]}});
    }
    return solve(n,graph,src,dst,k);

    
}
int main() {

    vector<vector<int>> flights = {{0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}};
    int n=5;
    int src = 0;
    int dst = 2;
    int k = 2;

    //Expected output is 7
    cout<<findCheapestPrice(n, flights, src, dst, k)<<endl;
    

    

    return 0;
}