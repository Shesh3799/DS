#include <bits/stdc++.h>
using namespace std;

/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals 
that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Link: https://leetcode.com/problems/merge-intervals/description/
*/

bool compare(vector<int> a, vector<int>b){
    return a[0]<b[0];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end(), compare);
    int start=intervals[0][0];
    int end=intervals[0][1];
    for(int i=0;i<intervals.size();i++){
        if(intervals[i][0]<=end){
            start= min(intervals[i][0], start);
            end = max(end, intervals[i][1]);
        }
        else{
            result.push_back({start,end});
            start=intervals[i][0];
            end=intervals[i][1];
        }
    }
    
    result.push_back({start,end});
    
    return result;
}

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = merge(intervals);
    for(auto it: result){
        cout<<"{"<<it[0]<<","<<it[1]<<"}"<<endl;
    }
    return 0;
}