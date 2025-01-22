#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Link: https://leetcode.com/problems/partition-equal-subset-sum/description/
*/

bool subArrayWithGivenSum(vector<int> &nums, int target, int n, vector<vector<int>> &dp)
{
    if (n == 0 || target < 0)
        return false;
    if (target == 0)
        return true;

    if (dp[n][target] != -1)
        return dp[n][target];

    bool in = false, ex = false;
    if (nums[n - 1] <= target)
    {
        in = subArrayWithGivenSum(nums, target - nums[n - 1], n - 1, dp);
    }
    ex = subArrayWithGivenSum(nums, target, n - 1, dp);
    return dp[n][target] = in || ex;
}
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (auto num : nums)
    {
        sum += num;
    }

    // If sum is not divisible by 2 then partition is not possible
    if (sum % 2 != 0)
        return false;

    vector<vector<int>> dp(nums.size() + 1, vector<int>((sum / 2) + 2, -1));

    return subArrayWithGivenSum(nums, sum / 2, nums.size(), dp);
}

int main()
{
    vector<int> nums = {3, 3, 3, 4, 5};
    cout << canPartition(nums) << endl;
    return 0;
}