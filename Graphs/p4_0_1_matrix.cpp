#include <bits/stdc++.h>
using namespace std;

/*

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Link: https://leetcode.com/problems/01-matrix/description/
*/

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 0));
    int vis[n][m];
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            } else {
                vis[i][j] = 0;
            }
        }
    }

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, -1, 0, 1};
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                vis[nrow][ncol] == 0) {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }

    return dist;
}

int main() {
    vector<vector<int>> input = {{0,0,0},{0,1,0},{1,1,1}};

    updateMatrix(input);

    return 0;
}