#include <bits/stdc++.h>
using namespace std;

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
using all the original letters exactly once

Input: s = "anagram", t = "nagaram"

Output: true

Link: https://leetcode.com/problems/valid-anagram/description/
*/

bool isAnagram(string s, string t) {
    //If length are not same then they are not anagram
    if(s.length()!=t.length()) return false;
    
    int arr[256] = {0};
    for(int i=0;i<s.length(); i++){
        arr[s[i]]++;
        arr[t[i]]--;
    }

    for(int i=0;i<256;i++){
        if(arr[i]!=0) return false;
    }
    return true;
}

int main() {
    string s = "anagram", t = "nagaram";

    cout<<isAnagram(s,t)<<endl;

    return 0;
}