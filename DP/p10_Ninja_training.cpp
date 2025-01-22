#include <bits/stdc++.h>
using namespace std;

/*

Geek is going for a training program. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day.
As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his merit points as you are given a 2D array
of points arr, corresponding to each day and activity.

Example:
Input: n = 3 and arr[]= [[1,2,5],[3,1,1],[3,3,3]]
Output:11
Explanation: Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and
earn 3 points so, maximum point is 11.

Link: https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training

*/

int maximumPointsMemo(vector<vector<int>> &arr, int n, int prev, vector<vector<int>> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n][prev] != -1)
        return dp[n][prev];

    int maximum_points = 0;
    for (int i = 1; i <= 3; i++)
    {
        if (i != prev)
        {
            maximum_points = max(
                maximum_points,
                arr[n - 1][i - 1] + maximumPointsMemo(arr, n - 1, i, dp));
        }
    }
    return dp[n][prev] = maximum_points;
}
int maximumPoints(vector<vector<int>> &arr, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(4, -1));
    return maximumPointsMemo(arr, n, 0, dp);
}

int main()
{

    return 0;
}