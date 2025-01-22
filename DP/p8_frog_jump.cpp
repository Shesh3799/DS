#include <bits/stdc++.h>
using namespace std;

/*
Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps.
A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump
is abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used
by the Geek to jump from stair 0 to stair N-1.

Input: n = 4, height = {10 20 30 10}
Output: 20
Explanation:
Geek jump from 1st to 2nd stair(|20-10| = 10 energy lost). Then a jump from the 2nd to the last stair(|10-20| = 10 energy lost). So, total energy lost is 20 which is the minimum.

Link: https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump
*/

int memorization(vector<int> &height, int n, vector<int> &dp)
{
    if (n == 1)
        return 0; // Base case: Starting from the 1st stair (1-based index)

    if (dp[n] != -1)
        return dp[n]; // Return cached result if available

    // Compute energy for one-step jump
    int jumpOne = memorization(height, n - 1, dp) + abs(height[n - 1] - height[n - 2]);

    // Compute energy for two-step jump
    int jumpTwo = INT_MAX;
    if (n > 2)
    {
        jumpTwo = memorization(height, n - 2, dp) + abs(height[n - 1] - height[n - 3]);
    }

    // Store the result in dp
    dp[n] = min(jumpOne, jumpTwo);
    return dp[n];
}

int minimumEnergy(vector<int> &height, int n)
{
    vector<int> dp(n + 1, -1);
    return memorization(height, n, dp);
}

int main()
{
    vector<int> height = {10, 20, 30, 10};
    int n = height.size();
    cout << minimumEnergy(height, n) << endl;
    return 0;
}