#include <bits/stdc++.h>
using namespace std;

/*

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
    * All the visited cells of the path are 0.
    * All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/

*/

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    queue<pair<int,int>> q;
    int n=grid.size();
    int m = grid[0].size();
    if(grid[0][0]==1) return -1;
    q.push({0,0});
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    distance[0][0]=1;
    vector<vector<int>> delta = {
        {0,-1},//left
        {0,+1}, //right
        {-1,0}, //top
        {+1,0}, //bottom
        {-1,-1}, //top left diagonal
        {-1,+1}, //top right diagonal
        {+1,-1}, //bottom left diagonal
        {+1,+1}, //bottom right diagonal
        };
    while(q.empty()==false){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i=0;i<delta.size();i++){
            int nrow = row + delta[i][0];
            int ncol = col + delta[i][1];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0){
                int newDistance = distance[row][col] + 1;
                if(newDistance < distance[nrow][ncol]){
                    distance[nrow][ncol]=newDistance;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    if(distance[n-1][m-1]==INT_MAX) return -1;
    return distance[n-1][m-1];
}

int main() {

    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};

    //Expected output = 4
    cout<<shortestPathBinaryMatrix(grid)<<endl;
    

    return 0;
}