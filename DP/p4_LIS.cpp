#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Link: https://leetcode.com/problems/longest-increasing-subsequence/description/
*/

int getAns(vector<int>& arr, int n, int prev_index, vector<vector<int>>& dp) {
    if (n == arr.size())
        return 0;
        
    if (dp[n][prev_index + 1] != -1)
        return dp[n][prev_index + 1];
    
    int notTake = 0 + getAns(arr, n+1, prev_index, dp);
    
    int take = 0;
    
    if (prev_index == -1 || arr[n] > arr[prev_index]) {
        take = 1 + getAns(arr, n+1, n, dp);
    }
    
    return dp[n][prev_index + 1] = max(notTake, take);
}



int lengthOfLIS(vector<int>& nums) {
    // Create a 2D DP array initialized to -1
    int n= nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return getAns(nums, 0, -1, dp);
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout<<"LIS is "<<lengthOfLIS(nums)<<endl;

    return 0;
}