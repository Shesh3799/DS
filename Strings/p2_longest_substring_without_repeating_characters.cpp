#include <bits/stdc++.h>
using namespace std;

/*
Given a string s, find the length of the longest 
substring  without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Tags: Sliding window

Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/

int lengthOfLongestSubstring(string s) {
    if(s==" ") return 1;
    int arr[256] = {0};
    int count = 0;
    int max_count = 0;
    int start=0;
    for(int i=0;i<s.length();i++){
        //If count is not zero indicated duplicate letter
        if(arr[s[i]]!=0){
            max_count=max(count, max_count);
            while(s[start]!=s[i]) {
                arr[s[start++]] = 0;
            }
            start++;
            count=i-start;
        }
        arr[s[i]]++;
        count++;
    }
    max_count = max(count, max_count);
    return max_count;
}

int main() {
    string s = "abcabcbb";

    cout<<"Longest substring without repeating is : "<<lengthOfLongestSubstring(s)<<endl;

    return 0;
}