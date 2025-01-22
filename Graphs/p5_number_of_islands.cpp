#include <bits/stdc++.h>
using namespace std;

/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all 
four edges of the grid are all surrounded by water.

Link: https://leetcode.com/problems/number-of-islands/description/
*/

void dfs(vector<vector<char>>& grid, int row, int col, vector<pair<int,int>>& distance){
    grid[row][col]='0';
    for(int i=0; i<distance.size(); i++){
        int nrow=row+distance[i].first;
        int ncol=col+distance[i].second;
        if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size()){
            if(grid[nrow][ncol]=='1'){
                dfs(grid, nrow,ncol,distance);
            }
        }
    }
} 
int numIslands(vector<vector<char>>& grid) {
    vector<pair<int,int>> distance = {{0,-1},{0,1},{-1,0},{1,0}};
    int n = grid.size();
    if(n==0) return 0;
    int m=grid[0].size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                count++;
                dfs(grid, i, j, distance);
            }
        }

    }
    return count;
}

int main() {
    vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout<<numIslands(grid)<<endl;

    return 0;
}