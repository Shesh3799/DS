#include <bits/stdc++.h>
using namespace std;

/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements 
in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length 
of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. 
nums2 has a length of n.

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Link: https://leetcode.com/problems/merge-sorted-array/description/
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int e1 = m-1;
    int e2 = n-1;
    int idx = n+m-1;
    while(idx>=0 && e1>=0 && e2>=0){
        if(nums1[e1]>nums2[e2]){
            nums1[idx--]=nums1[e1--];
        }
        else{
            nums1[idx--]=nums2[e2--];
        }
    }
    while(e2>=0 && idx>=0){
        nums1[idx--]=nums2[e2--];
    }
    
}

int main() {
    int m = 3, n=3;
    vector<int> nums1 = {1,2,3,0,0,0},  nums2 = {2,5,6};
    merge(nums1, m, nums2, n);
    for(auto it: nums1){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}