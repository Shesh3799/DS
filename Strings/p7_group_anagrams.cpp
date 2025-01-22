#include <bits/stdc++.h>
using namespace std;

/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Link: https://leetcode.com/problems/group-anagrams/description/
*/

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    for (string s : strs)
    {
        string t = s;
        sort(t.begin(), t.end());
        mp[t].push_back(s);
    }
    vector<vector<string>> anagrams;
    for (auto p : mp)
    {
        anagrams.push_back(p.second);
    }
    return anagrams;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = groupAnagrams(strs);

    for (const auto &it : result)
    {
        cout << "[ ";
        for (const auto &s : it)
        {
            cout << s << " ";
        }
        cout << "]";
    }

    return 0;
}