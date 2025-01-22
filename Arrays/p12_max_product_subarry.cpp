#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, find a subarray  that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Link: https://leetcode.com/problems/maximum-product-subarray/description/
*/


int maxProduct(vector<int>& nums) {
    int max_product = nums[0], min_product = nums[0], global_max = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int current = nums[i];
        
        // Store max_product temporarily as it will be updated
        int temp_max = max({current, current * max_product, current * min_product});
        min_product = min({current, current * max_product, current * min_product});
        
        max_product = temp_max;
        global_max = max(global_max, max_product);
    }

    return global_max;
}

int main() {
    vector<int> arr ={2,3,-2,4};
    cout<<maxProduct(arr)<<endl;

    return 0;
}