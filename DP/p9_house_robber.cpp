#include <bits/stdc++.h>
using namespace std;

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount
of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Link: https://leetcode.com/problems/house-robber/description/
*/

int solve(vector<int> &nums, int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
        return nums[0];

    if (dp[n] != -1)
        return dp[n];

    int robHouse = nums[n - 1] + solve(nums, n - 2, dp);
    int doNotRobHouse = solve(nums, n - 1, dp);

    return dp[n] = max(robHouse, doNotRobHouse);
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return solve(nums, n, dp);
}

int main()
{
    vector<int> house = {1, 2, 3, 1};
    cout << rob(house) << endl;

    return 0;
}