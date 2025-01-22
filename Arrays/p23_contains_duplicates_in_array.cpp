#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Link: https://leetcode.com/problems/contains-duplicate/description/

Brute force:
TC: O(n^2) and SC: O(1)

With sorting:
TC: O(nlog(n)) and SC: O(1)

With hashmap:
TC: O(n) and SC: O(n)
*/

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> dict;
    for (auto num : nums) {
        if (dict.count(num) > 0) return true;
        dict.insert(num);
    }
    return false;
}

int main() {
    vector<int> nums = {1,2,3,1};

    cout<<containsDuplicate(nums)<<endl;
    

    return 0;
}