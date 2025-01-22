#include <bits/stdc++.h>
using namespace std;

/*

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Link: https://leetcode.com/problems/search-a-2d-matrix/

*/


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size() ;
        int col = matrix[0].size() ;
        int s = 0 ;
        int e = row*col - 1 ;
        int m = s+(e-s)/2;
        while(s<=e){
            int element = matrix[m/col][m%col];
            if(target == element){
                return true;
            }
            else if(target <= element){
                e=m-1;
            }
            else {
                s=m+1;
            }
            m = s+(e-s)/2;
        }
        return false;
}

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    cout<<searchMatrix(matrix, target)<<endl;
    return 0;
}