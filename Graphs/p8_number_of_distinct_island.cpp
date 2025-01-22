#include <bits/stdc++.h>
using namespace std;
/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms 
an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

https://www.geeksforgeeks.org/problems/number-of-distinct-islands/0
*/

void dfs(vector<vector<int>>& grid, vector<pair<int,int>>& coordinates, vector<vector<bool>>& visited, int row, int col, int baseRow, int baseCol){
    int n = grid.size();
    int m = grid[0].size();
    if(visited[row][col]==true)
        return;
    coordinates.push_back({row-baseRow, col-baseCol});
    visited[row][col]=true;
    
    vector<pair<int,int>> distance = {{0,-1},{0,1},{-1,0},{1,0}};
    
    for(int i=0;i<distance.size(); i++){
        int nrow = row+distance[i].first;
        int ncol = col+distance[i].second;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && visited[nrow][ncol]==false){
            dfs(grid, coordinates, visited, nrow, ncol, baseRow, baseCol);
        }
    }
    
}
int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    set<vector<pair<int,int>>> st;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && visited[i][j]==false){
                vector<pair<int,int>> coordinates;
                dfs(grid, coordinates,visited, i, j, i,j);
                st.insert(coordinates);
            }
        }
    }
    return st.size();
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };
    int expectedOutput = 1;
    int actualOutput = countDistinctIslands(grid);
    if(actualOutput!=expectedOutput)
    {
        cout<<"The actual output is "<<actualOutput<<" but expected output is "<<expectedOutput<<endl;
    }
    else
    {
        cout<<"Actual and Expected output are matching\n";
    }
  
    return 0;
};