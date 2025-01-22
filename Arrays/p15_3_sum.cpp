#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Link: https://leetcode.com/problems/3sum/
*/
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    
    set<vector<int>> result;
    int prev=INT_MAX;
    for(int i=0;i<n-2;i++){
        //We reached the positive element in sorted array so there is no way
        // We can get some as 0 with all positive numbers
        if(nums[i]>0) break;
        //Previous and current element are same so skip
        if(prev==nums[i]) continue;
        prev=nums[i];
        int low = i+1;
        int high = n-1;
        while(low<high){
            int curr_sum = nums[i] + nums[low] + nums[high];
            if(curr_sum == 0){
                result.insert({nums[i], nums[low], nums[high]});
                low++;
                high--;
            }else if(curr_sum>0){
                high--;
            } else{
                low++;
            }
        }
    }
    vector<vector<int>> final_ans(result.begin(), result.end());
    return final_ans;
    
}

int main() {vector<int> arr = { -1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(arr);
    //Expected [-1 -1 2 ] [-1 0 1 ] 
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    

    return 0;
}