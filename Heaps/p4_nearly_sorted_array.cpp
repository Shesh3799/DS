#include <bits/stdc++.h>
using namespace std;

/*
You’re given an array/list 'ARR' of N elements, where each element is at most K away from its target position(Position if the array was sorted). 
Now, your task is to devise an algorithm that sorts the given array in O(N log K) time.

For example:
Let us consider 'K' is 3, an element at index 4 in the sorted array, can be at indexes 1, 2, 3, 4, 5, 6, 7 in the given array, 
because the absolute difference of all these indices with 4 is at most 3.

Sample Input 1:
1
7 3 
6 5 3 2 8 10 9
Sample Output 1:
2 3 5 6 8 9 10

Link: https://www.naukri.com/code360/problems/nearly-sorted_982937?leftPanelTabValue=PROBLEM
*/


vector<int> nearlySorted(vector < int >& array, int n, int k) {
    // Write your code here.

    priority_queue<int, vector<int>, greater<int>> pq;

    vector<int> result;

    for(int i=0;i<k;i++){
        pq.push(array[i]);
    }

    for(int i=k;i<n;i++)
    {
        if(pq.size()>k){
            result.push_back(pq.top());
            pq.pop();
        }
        
        pq.push(array[i]);
    }
    while(pq.empty()==false){
        result.push_back(pq.top());
        pq.pop();
    }
    return result;

}

int main() {

    int k = 3;

    vector<int> arr = {6,5,3,2,8,10,9};

    vector<int> result = nearlySorted(arr, arr.size(), k);

    //Output: 2 3 5 6 8 9 10
    
    return 0;
}