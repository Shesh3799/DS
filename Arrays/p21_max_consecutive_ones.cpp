#include <bits/stdc++.h>
using namespace std;

/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]

Tags: Two pointers, sliding window

Link: https://leetcode.com/problems/max-consecutive-ones-iii/description/
*/

//Solution O(2N)
int longestOnes_1(vector<int>& nums, int k) {
    int zeroes = 0;
    int r = 0, l=0;
    int max_len = 0;
    while(r<nums.size()){
        //If we encounter 0 in subarry then increment count
        if(nums[r]==0) zeroes++;
        
        //Till the count of zeroes is not valid shrink the window
        while(zeroes>k){
            if(nums[l]==0) zeroes--;
            l++;
        }
        //Check the max length
        max_len = max(max_len, r-l+1);
        r++;
    }
    return max_len;
}

// Solution O(n)
// Here we avoid internal while loop and the idea is that we will maintain the maximum window length
// obtained so far and if at any given point in time the window becomes valid will consider that
int longestOnes_2(vector<int>& nums, int k) {
    int zeroes = 0;
    int r = 0, l=0;
    int max_len = 0;
    while(r<nums.size()){
        if(nums[r]==0) zeroes++;
        if(zeroes>k){
            if(nums[l]==0) zeroes--;
            l++;
        }
        else max_len = max(max_len, r-l+1);
        r++;
    }
    return max_len;
}


int main() {
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout<<"Longest subarray : "<<longestOnes_2(arr, k)<<endl;

    return 0;
}