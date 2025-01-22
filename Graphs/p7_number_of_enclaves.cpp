#include <bits/stdc++.h>
using namespace std;

/*

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Link: https://leetcode.com/problems/number-of-enclaves/description/

Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
*/
void fill(vector<vector<int>>& board, int sr, int sc, vector<vector<bool>>& visited){
    int n = board.size();
    int m = board[0].size();
    if(visited[sr][sc]==false) return;
    visited[sr][sc]=false;
    vector<pair<int,int>> distance = {{0,-1},{0,1},{-1,0},{1,0}};
    for(int i=0;i<distance.size();i++){
        int nrow = sr + distance[i].first;
        int ncol = sc + distance[i].second;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]==1){
            fill(board, nrow, ncol, visited);
        }
    }
}


int numEnclaves(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m,true));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0 || j==0 || i == n-1 || j== m-1) && grid[i][j]==1 && visited[i][j]==true){
                fill(grid, i,j,visited);
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && visited[i][j]==true){
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    int expectedOutput = 3;
    int actualOutput = numEnclaves(grid);
    if(actualOutput!=expectedOutput)
    {
        cout<<"The actual output is "<<actualOutput<<" but expected output is "<<expectedOutput<<endl;
    }
    else
    {
        cout<<"Actual and Expected output are matching\n";
    }

    return 0;
}