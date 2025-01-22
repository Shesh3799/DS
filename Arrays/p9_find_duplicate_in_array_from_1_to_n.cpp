#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

Link: https://leetcode.com/problems/find-the-duplicate-number/description/
*/

int findDuplicate(vector<int>& nums) {
    int n = nums.size()+1;
    for(int i=0;i<nums.size();i++){
        //Store size + 1 value to every index
        int num = nums[i]%n;
        nums[num-1]+=n;
        //If we have stored size+1 twice then this is duplicate
        if(nums[num-1]/n>1) return num;

    }
    return -1;
}

int main() {
    

    return 0;
}