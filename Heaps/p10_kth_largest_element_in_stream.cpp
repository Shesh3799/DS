#include <bits/stdc++.h>
using namespace std;

/*
You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.

Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for (int num : nums)
        {
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size()>k){
            pq.pop();
        }
        return pq.top();
    }
};

int main() {
    int k=4;
    vector<int> nums = {7, 7, 7, 7, 8, 3};
    KthLargest kthLargest(k, nums);
    //output = 7 7 7 8
    cout<<kthLargest.add(2) <<" ";
    cout<<kthLargest.add(10)<<" ";
    cout<<kthLargest.add(9) <<" ";
    cout<<kthLargest.add(9) <<" ";

    cout<<endl;

    return 0;
}