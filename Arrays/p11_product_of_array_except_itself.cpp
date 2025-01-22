#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Link: https://leetcode.com/problems/product-of-array-except-self/

*/

vector<int> productExceptSelf(vector<int>& nums) {
    long long result=1;
    int zero_count=0;
    for(int num: nums){
        if(num==0) {
            zero_count++;
            continue;
        }
        result=result*num;
    }
    vector<int> ans(nums.size(),0);
    if(zero_count>1) return ans;
    if(zero_count>0){
        int i=0;
        for(int num: nums){
            if(num==0) {
                ans[i++]=result;
            }
            else ans[i++]=0;            
        }
        return ans;
    }
    
    int i =0;
    for(int num:nums){
        ans[i++]=(result/num);
    }
    return ans;
}

int main() {
    

    return 0;
}