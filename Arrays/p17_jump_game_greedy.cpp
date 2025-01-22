#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array 
represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Algorithm / Intuition:
A greedy algorithm makes a series of choices, each of which looks the best at the moment, with the hope that these local 
optimizations will lead to a globally  optimal solution. The key idea is to make the best possible choice at each step 
without considering the overall problem.

For this problem, we keep track of the farthest position we can reach at any point in time. We iterate over the array 
and keep making the greedy choice of reaching the farthest by comparing if the current index can be reached by the previous 
indices or not.

If we reach an index that is beyond the farthest position we can reach, we return false. Else, we keep updating the farthest 
position with the maximum index we can reach from the current index.

Link: https://leetcode.com/problems/jump-game/description/
*/

bool canJump(vector<int>& nums) {
    // Initialize the maximum
    // index that can be reached
    int maxIndex = 0;

    // Iterate through each
    // index of the array
    for(int i = 0; i < nums.size(); i++){
        // If the current index is greater
        // than the maximum reachable index
        // it means we cannot move forward
        // and should return false
        if (i > maxIndex){
            return false;
        }

        // Update the maximum index
        // that can be reached by comparing
        // the current maxIndex with the sum of
        // the current index and the
        // maximum jump from that index
        maxIndex = max(maxIndex, i + nums[i]);
    }
    
    // If we complete the loop,
    //it means we can reach the
    // last index
    return true;
}

int main() {
    vector<int> nums = {4, 3, 7, 1, 2};
    
    cout << "Array representing maximum jump from each index: ";
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    
    bool ans = canJump(nums);
    
    if (ans) {
        cout << "It is possible to reach the last index." << endl;
    } else {
        cout << "It is not possible to reach the last index." << endl;
    }
    
    return 0;
}