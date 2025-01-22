#include <bits/stdc++.h>
using namespace std;

/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array of arr[], 
where arr[i]  is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow :

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. 
The picked fruits must fit in one of the baskets.

Once you reach a tree with fruit that cannot fit in your baskets, you must stop. Given the integer array of fruits, return the maximum number of fruits you 
can pick.

Input: arr[] = [3, 1, 2, 2, 2, 2]
Output: 5
Explanation: It's optimal to pick from the last 5 trees. Please note that we do not pick the first basket as we would have to stop at thrid tree 
which would result in only 2 fruits collected.

Tags: Sliding window, Two pointer

Link: https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1
*/

// O(2N) solution
int totalFruits_1(vector<int> &arr) {
    unordered_map<int, int> umap;
    int l=0, r=0, max_len=0;
    while(r<arr.size()){
        umap[arr[r]]++;
        while(umap.size()>2){
            umap[arr[l]]--;
            if(umap[arr[l]]==0){
                umap.erase(arr[l]);
            }
            l++;
        }
        max_len = max(max_len, r-l+1);
        
        r++;
    }
    return max_len;
}

// O(N) solution
int totalFruits_2(vector<int> &arr) {
    unordered_map<int, int> umap;
    int l=0, r=0, max_len=0;
    while(r<arr.size()){
        umap[arr[r]]++;
        if(umap.size()>2){
            umap[arr[l]]--;
            if(umap[arr[l]]==0){
                umap.erase(arr[l]);
            }
            l++;
        }
        else max_len = max(max_len, r-l+1);
        
        r++;
    }
    return max_len;
}

int main() {

    vector<int> arr = {3, 1, 2, 2, 2, 2};
    cout<<"Total fruits : "<<totalFruits_2(arr)<<endl;
    
    return 0;
}