#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

Link: https://leetcode.com/problems/container-with-most-water/description/
*/

int bruteForceMethod(vector<int>& arr){
    //Time Complexity: O(n^2). 
    int area = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Calculating the max area
            area = max(area, min(arr[j], arr[i]) * (j - i));
        }
    }
    return area;
}

int maxArea(vector<int>& height) {
    //Time complexity: O(n)
    // return bruteForceMethod(height);
    int left = 0;
    int right = height.size()-1;
    int max_water = 0;
    while(left<right){
        max_water = max(max_water, min(height[left], height[right])*(right-left));
        if(height[left]<height[right]) left++;
        else right--;
    }
    return max_water;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    //Expected output 49
    cout<<"Maximum water in container is "<<maxArea(height)<<endl;
    return 0;
}