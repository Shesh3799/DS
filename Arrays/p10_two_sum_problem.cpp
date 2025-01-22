#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Brute force:
TC: O(n^2) and SC: O(n)

With Sorting: We can use this if return type is boolean
TC: O(nlog(n)) and SC: O(1)

With hashmap:
TC: O(n) and SC: O(n)
*/

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if (numMap.count(complement)) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }

    return {}; // No solution found
}

int main() {
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> result = twoSum(arr, target);
    if(result.size()>0){
        cout<<"Found 2 sum at index "<<result[0]<<" and "<<result[1]<<endl;
    }
    else{
        cout<<"Two sum not found\n";
    }

    return 0;
}