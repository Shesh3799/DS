#include <bits/stdc++.h>
using namespace std;

/*
Given an unsorted array and two numbers x and k, find k closest values to x.
Input : arr[] = {10, 2, 14, 4, 7, 6}, x = 5, k = 3 . 

*/

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int,int>> pq;

    for(int i=0;i<arr.size();i++){
        pq.push(make_pair(abs(arr[i]-x), i));
        if(pq.size()>k){
            pq.pop();
        }
    }

    vector<int> result;
    
    while(pq.empty()==false){
        int index = pq.top().second;
        result.push_back(arr[index]);
        pq.pop();
    }

    return result;
}


int main() {
    

    return 0;
}