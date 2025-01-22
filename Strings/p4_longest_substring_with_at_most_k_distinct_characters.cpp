#include <bits/stdc++.h>
using namespace std;

/*

You are given a string 'str' and an integer ‘K’. Your task is to find the length of the largest substring with at most ‘K’ distinct characters.

For example:
You are given ‘str’ = ‘abbbbbbc’ and ‘K’ = 2, then the substrings that can be formed are [‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.

Tags: Sliding Window, Two Pointer

This is variation of Arrays/p22_fruit_into_baskets.cpp

Link: https://www.naukri.com/code360/problems/distinct-characters_2221410?leftPanelTabValue=PROBLEM

*/

int kDistinctChars(int k, string &str)
{
    unordered_map<char, int> umap;
    int l=0, r=0, max_len=0;
    while(r<str.size()){
        umap[str[r]]++;
        if(umap.size()>k){
            umap[str[l]]--;
            if(umap[str[l]]==0){
                umap.erase(str[l]);
            }
            l++;
        }
        else max_len = max(max_len, r-l+1);
        
        r++;
    }
    return max_len;
}

int main() {
    

    return 0;
}