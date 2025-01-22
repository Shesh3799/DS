#include <bits/stdc++.h>
using namespace std;

/*

You are given an m x n grid where each cell can have one of three values:
* 0 representing an empty cell,
* 1 representing a fresh orange, or
* 2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Link: https://leetcode.com/problems/rotting-oranges/description/

*/

int orangesRotting(vector<vector<int>>& grid) {
    //BFS
    
    if(grid.size()==0)
        return 0;
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));
    //{{r,c},time}
    queue<pair<pair<int, int>,int>> q;

    int fresh = 0;
    for(int i=0;i<n; i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1) fresh++;
            else if(grid[i][j] == 2){
                q.push({{i,j},0});
                visited[i][j]=2;
            }
        }
    }

    //left,right,top,bottom
    int deltaRow[4] = {0,0,-1,1};
    //left,right,top,bottom
    int deltaCol[4] = {-1,1,0,0};
    int rotten = 0;
    int tm_max = 0;
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int row=r+deltaRow[i];
            int col=c+deltaCol[i];
            if(row>=0 && row<n && col>=0 && col<m){
                if(grid[row][col]==1 && !(visited[row][col]==2)){
                    q.push({{row,col},t+1});
                    visited[row][col]=2;
                    rotten++;
                }
            }
        }
        tm_max = max(tm_max, t);
    }
    if(fresh!=rotten) return -1;
    return tm_max;
    
}

int main() {
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout<<orangesRotting(grid)<<endl;

    return 0;
}