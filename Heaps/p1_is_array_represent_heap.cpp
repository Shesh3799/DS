#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr of size n, the task is to check if the given array can be a level order representation of a Max Heap.

Example:
arr[] = {90, 15, 10, 7, 12, 2} then output = 1
The given array represents below tree which is max heap
       90
     /    \
   15      10
  /  \     /
7    12  2

GFG: https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1
*/

bool isMaxHeap(vector<int>arr)
{
    int n = arr.size();
    queue<int> q;
    q.push(0);
    while(q.empty()==false)
    {
        int current = q.front();
        q.pop();
        int left = 2*current+1;
        int right = 2*current+2;
        if(left<n){
            if(arr[left]<=arr[current])
                q.push(left);
            else return false;
        }
        if(right<n){
            if(arr[right]<=arr[current])
                q.push(right);
            else return false;
        }
    }
    return true;
}

int main() {
    vector<int> arr = {90, 15, 10, 7, 12, 2};
    //Expected output is 1
    cout<<isMaxHeap(arr)<<endl;
    return 0;
}