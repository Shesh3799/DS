#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

Time Complexity: O(NLogK)

Leetcode: https://leetcode.com/problems/kth-largest-element-in-an-array/description/
*/

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<k;i++){
        pq.push(nums[i]);
    }
    for(int i=k;i<nums.size();i++){
        pq.push(nums[i]);
        pq.pop();
    }
    return pq.top();
}

int main() {
    

    return 0;
}