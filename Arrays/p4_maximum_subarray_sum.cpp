#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, find the subarray  with the largest sum, and return its sum.

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Link: https://leetcode.com/problems/maximum-subarray/description/
*/

int maximumSubArraySum(vector<int>& arr){
    int max_sum = INT_MIN;
    int n = arr.size();
    int curr_sum=0;
    for(int i=0;i<n;i++){
        curr_sum+=arr[i];
        curr_sum=max(curr_sum, arr[i]);
        max_sum=max(curr_sum, max_sum);
    }
    return max_sum;
}

int main() {
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    long long maxSum = maximumSubArraySum(arr);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}