#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Link:https://leetcode.com/problems/coin-change/description/
*/

int coinChangeMemo(vector<int>& coins, int amount, int n, vector<vector<int>>& dp){
    if(n==0) return INT_MAX-1;
    if(amount==0) return 0;

    if(dp[n][amount]!=-1)
        return dp[n][amount];

    //Consider the coin
    int taking = INT_MAX;
    if(amount>=coins[n-1]){
        taking = 1 + coinChangeMemo(coins, amount-coins[n-1], n, dp);
    }
    int nottaking = 0 + coinChangeMemo(coins, amount, n-1, dp);

    return dp[n][amount]=min(taking, nottaking);

}
int coinChangeTopDown(vector<int>& coins, int amount){
        
    int n = coins.size();
    vector<vector<int>> dp(n+1, vector<int>(amount+1));
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < amount + 1; j++)
            if (i == 0 || j == 0)
                dp[i][j] = (j == 0) ? 0 : INT_MAX - 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<amount+1;j++){
            if(j<coins[i-1]){
                dp[i][j]=dp[i-1][j];
            } else {
                dp[i][j] = min(0 + dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }
    }
    return dp[n][amount]>=INT_MAX-1?-1:dp[n][amount];
}
int coinChange(vector<int>& coins, int amount) {
    //Meomoization
    // vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
    // int no_of_coin = coinChangeMemo(coins, amount, coins.size(), dp);
    // return no_of_coin>=INT_MAX-1?-1:no_of_coin;
    
    //Top down
    return coinChangeTopDown(coins, amount);

}

int main() {
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout<<coinChange(coins, amount)<<endl;

    return 0;
}