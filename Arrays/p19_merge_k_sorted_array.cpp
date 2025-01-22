#include <bits/stdc++.h>
using namespace std;

/*

You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/list 
such that the output array/list should be sorted in ascending order.

Link: https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379

*/

vector<int> mergeTwoSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n= nums1.size();
    int m= nums2.size();
    vector<int> result(n+m);
    int idx = 0;
    int i=0, j =0;
    while(i<n && j<m){
        if(nums1[i]<nums2[j])result[idx++]=nums1[i++];
        else result[idx++]=nums2[j++];
    }
    while(i<n) result[idx++]=nums1[i++];
    while(j<m) result[idx++]=nums2[j++];

    return result;
}

//Option 1: Merge in pair of two
vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k)
{
    vector<int> result = kArrays[0];
    // Iteratively merge the result with each of the remaining arrays
    for (int i = 1; i < k; i++) {
        result = mergeTwoSortedArrays(result, kArrays[i]);
    }
    
    return result;
}

//Option 2: Merge using heap
//Pending
//Refer https://www.geeksforgeeks.org/merge-k-sorted-arrays-set-2-different-sized-arrays/
// vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k){
//     int length = 0;
//     for(int i=0;i<k;i++){
//         length+=kArrays[i].size();
//     }
//     vector<int> result(length);

//     // Min heap of size k
//     priority_queue<int, vector<int>, greater<int>> pq;

//     for(int i=0;i<k;i++){

//     } 

// }


int main() {
    vector<vector<int>> kArrays = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    int k = 3;
    vector<int> result = mergeKSortedArrays(kArrays, k);

    for(auto x: result){
        cout<<x<<" ";
    }

    return 0;
}