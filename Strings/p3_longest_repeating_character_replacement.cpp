#include <bits/stdc++.h>
using namespace std;

/*

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Tags: Slidng Window, Two pointer

*/

//Solution O(2N)
int characterReplacement(string s, int k) {
    int arr[256] = {0};
    int max_length = 0;
    int l=0, r=0;


    while(r<s.length()){
        arr[s[r]]++;
        int max_freq = *max_element(arr, arr + 256);
        int length = r-l+1;
        while(length-max_freq>k){
            arr[s[l]]--;
            l++;
            length = r-l+1;
            max_freq = *max_element(arr, arr + 256);
        }
        
        max_length = max(max_length, length);
        r++;
    }
    return max_length;
}

//Solution O(N)
int characterReplacement_2(string s, int k) {
    int arr[256] = {0};
    int max_length = 0;
    int l=0, r=0;


    while(r<s.length()){
        arr[s[r]]++;
        int max_freq = *max_element(arr, arr + 256);
        int length = r-l+1;
        if(length-max_freq>k){
            arr[s[l]]--;
            l++;
            length = r-l+1;
            max_freq = *max_element(arr, arr + 256);
        }
        else
            max_length = max(max_length, length);
        r++;
    }
    return max_length;
}

int main() {
    string s = "AABABBA"; 
    int k = 1;

    cout<<characterReplacement(s, k)<<endl;

    return 0;
}