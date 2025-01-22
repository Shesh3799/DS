#include <bits/stdc++.h>
using namespace std;

/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the 
height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) 
(i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Link: https://leetcode.com/problems/path-with-minimum-effort/description/

*/

int minimumEffortPath(vector<vector<int>>& heights) {

    //{diff, nrow, col}
    typedef pair<int, pair<int, int>> PIII;

    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));

    //Max heap
    priority_queue<PIII, vector<PIII>, greater<PIII>> pq;
    pq.push({0,{0,0}});
    distance[0][0]=0;

    vector<pair<int,int>> delta = {{0,-1}, {0,+1},{-1,0},{1,0}};

    while(pq.empty()==false){
        int diff = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();
        if(row==n-1 && col==m-1) return diff;
        for(int i=0;i<delta.size();i++){
            int nrow = row+delta[i].first;
            int ncol = col+delta[i].second;

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                int new_diff = max(diff, abs(heights[row][col]-heights[nrow][ncol]));
                if(new_diff<distance[nrow][ncol]){
                    distance[nrow][ncol]=new_diff;
                    pq.push({new_diff,{nrow,ncol}});
                }
            }
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> heights = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};

    // Expected output is 0
    cout<<minimumEffortPath(heights)<<endl;

    return 0;
}