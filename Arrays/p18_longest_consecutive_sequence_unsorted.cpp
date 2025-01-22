#include <bits/stdc++.h>
using namespace std;

/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Link:https://leetcode.com/problems/longest-consecutive-sequence/
*/


int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> umap;
    for(int num: nums){
        umap[num]=1;
    }
    int max_count = 0;
    for(int num: nums){
        if(umap.find(num)==umap.end()) continue;
        int cnt=umap[num];
        int temp = num;
        
        while(umap.find(num+1)!=umap.end()){
            cnt+=umap[num+1];
            num++;
            umap.erase(num);
        }
        max_count = max(max_count,cnt);
        umap[temp]=cnt;
    }
    return max_count;
    
}

int main() {
    

    return 0;
}