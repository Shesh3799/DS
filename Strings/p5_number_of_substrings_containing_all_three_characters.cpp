#include <bits/stdc++.h>
using namespace std;

/*

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are 
"abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

Tags: Sliding Window, Two pointer

Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
*/


int numberOfSubstrings(string s) {
    int hashMap[3] = {-1, -1, -1};
    int numberOfSubStrings = 0;

    for(int i=0;i<s.length();i++){
        hashMap[s[i]-'a'] = i;
        if(hashMap[0]!=-1 && hashMap[1]!=-1 && hashMap[2]!=-1){
            int minIdx = min(hashMap[0], min(hashMap[1], hashMap[2]));
            numberOfSubStrings+=minIdx+1;
        }
    }
    return numberOfSubStrings;
    
}

int main() {
    string s = "abcabc";
    cout<<numberOfSubstrings(s)<<endl;
    return 0;
}