#include <bits/stdc++.h>
using namespace std;

/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the 
relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both strings.

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Link: https://leetcode.com/problems/longest-common-subsequence/description/

*/

int lcsMemo(string& text1, string& text2, int n1, int n2, vector<vector<int>>& dp){
    if(n1==0 || n2==0) return 0;

    if(dp[n1][n2]!=-1) return dp[n1][n2];
    
    if(text1[n1-1]==text2[n2-1]){
        return dp[n1][n2] = 1+lcsMemo(text1, text2, n1-1, n2-1, dp);
    }
    
    return dp[n1][n2] = max(lcsMemo(text1, text2, n1-1, n2, dp), lcsMemo(text1, text2,n1, n2-1, dp));
}
int lcsTopDown(string text1, string text2, int n, int m){
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else break;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];

}
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();

    //Memoization
    // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    // return lcsMemo(text1, text2, n, m, dp);

    //Top DOwn
    return lcsTopDown(text1, text2, n, m);
}

int main() {
    string text1 = "abcde", text2 = "ace";
    cout <<"LCS is "<<longestCommonSubsequence(text1, text2)<<endl;

    return 0;
}