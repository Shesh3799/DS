#include <bits/stdc++.h>
using namespace std;

/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Link: https://leetcode.com/problems/sort-colors/description/
*/

void sortColors(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size()-1;

    while(mid<=high){
        //if mid=0 then swap mid with low and increment low and mid
        if(nums[mid]==0) {
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        //if mid=2 then swap mid with high and decrement high
        else if(nums[mid]==2) swap(nums[mid],nums[high--]);
        //if mid==1 then increment mid
        else mid++;
    }
    
}

int main() {
    vector<int> nums = {2,0,2,1,1,0};

    sortColors(nums);

    for(auto it: nums){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}