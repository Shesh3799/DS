#include <bits/stdc++.h>
using namespace std;

/*

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

* Connect: A cell is connected to adjacent cells horizontally or vertically.
* Region: To form a region connect every 'O' cell.
* Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the 
edge of the board. A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.

https://leetcode.com/problems/surrounded-regions/description/


*/

void fill(vector<vector<char>>& board, int sr, int sc, vector<vector<bool>>& visited){
    int n = board.size();
    int m = board[0].size();
    if(visited[sr][sc]==false) return;
    visited[sr][sc]=false;
    vector<pair<int,int>> distance = {{0,-1},{0,1},{-1,0},{1,0}};
    for(int i=0;i<distance.size();i++){
        int nrow = sr + distance[i].first;
        int ncol = sc + distance[i].second;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O'){
            fill(board, nrow, ncol, visited);
        }
    }
}
void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m,true));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0 || j==0 || i == n-1 || j== m-1) && board[i][j]=='O' && visited[i][j]==true){
                fill(board, i,j,visited);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O' && visited[i][j]==true){
                board[i][j]='X';
            }
        }
    }
    
}

void print(vector<vector<char>>& output){
    int n = output.size();
    int m = output[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<output[i][j];
        }
        cout<<endl;
    }
}

bool validate(vector<vector<char>>& output, vector<vector<char>>& expected_output){
    int n = output.size();
    int m = output[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(output[i][j]!=expected_output[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    
    vector<vector<char>> input_board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};

    vector<vector<char>> expected_output_board = {{'X','X','X','X'},{'X','X','X','X'},{'X','X','X','X'},{'X','O','X','X'}};

    solve(input_board);

    if(validate(input_board, expected_output_board)==true){
        cout<<"The answer is correct\n";
    } else{
        cout<<"The answer is not correct\n";
        cout<<"Expected answer:\n";
        print(expected_output_board);
        cout<<"Expected answer:\n";
        print(expected_output_board);
    }


    return 0;
}