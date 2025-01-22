#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Link: https://leetcode.com/problems/top-k-frequent-elements/description/

*/

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> umap;
    for(auto num: nums){
        umap[num]++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    for(auto& it:umap){
        pq.push(make_pair(it.second, it.first));
        if(pq.size()>k) pq.pop();
    }
    vector<int> result;
    while(pq.empty()==false){
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;

}


int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> result = topKFrequent(nums, k);

    // Output should contain {1,2}
    for(auto num : result){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}