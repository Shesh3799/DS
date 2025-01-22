#include <bits/stdc++.h>
using namespace std;

/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the 
permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array 
is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest 
possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].

Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

Link: https://leetcode.com/problems/next-permutation/description/
*/

//option 1
void next_permutation(int index, vector<int>& nums, vector<vector<int>>& result){
    if(index==nums.size()){
        result.push_back(nums);
        return;
    }
    for(int i=index;i<nums.size(); i++){
        swap(nums[index], nums[i]);
        next_permutation(index+1, nums, result);
        swap(nums[index], nums[i]);
    }
}

//option 2
//next_permutation(arr,arr+3);//using in-built function of C++

//option 3

vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;
}

int main() {
    

    return 0;
}