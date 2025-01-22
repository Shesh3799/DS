#include <bits/stdc++.h>
using namespace std;

/*
You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

"1" -> 'A'

"2" -> 'B'

...

"25" -> 'Y'

"26" -> 'Z'

However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

For example, "11106" can be decoded into:

"AAJF" with the grouping (1, 1, 10, 6)
"KJF" with the grouping (11, 10, 6)
The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
Note: there may be strings that are impossible to decode.

Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: s = "12"

Output: 2

Explanation:

"12" could be decoded as "AB" (1 2) or "L" (12).

Link: https://leetcode.com/problems/decode-ways/description/
*/

int decodingsMemo(string& s, int idx, vector<int>& dp){
    if(idx==s.length())
        return 1;
    if(idx>s.length()) return 0;
    if(s[idx]=='0') return 0;

    if(dp[idx]!=-1) return dp[idx];
    
    //option 1 is to consider only one letter
    int option1 = decodingsMemo(s, idx+1, dp);
    int option2 = 0;
    if(s[idx]=='1' || (s[idx]=='2' && idx<s.length()-1 && s[idx+1]<='6')){
        option2 = decodingsMemo(s, idx+2, dp);
    }

    return dp[idx] = option1 + option2;
}

int decodingTopDown(string s){
    int n = s.length();
    if (n == 0 || s[0] == '0') {
        return 0;
    }

    // dp[i] means the number of ways to decode the substring s[0..i-1]
    vector<int> dp(n + 1, 0);
    
    // Base case: there's one way to decode an empty string
    dp[0] = 1;
    
    // Fill the dp array from left to right
    for (int i = 1; i <= n; ++i) {
        // Single character decoding (s[i-1])
        if (s[i-1] != '0') {
            dp[i] += dp[i-1];
        }
        
        // Two character decoding (s[i-2]s[i-1])
        if (i > 1 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))) {
            dp[i] += dp[i-2];
        }
    }
    
    return dp[n];
}


int numDecodings(string s) {
    // vector<int> dp(s.length()+1, -1);
    // return decodingsMemo(s, 0, dp);

    return decodingTopDown(s);
}
int main() {
    string s = "110";
    cout<<"Number of decodings "<<numDecodings(s)<<endl;

    return 0;
}