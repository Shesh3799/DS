#include <bits/stdc++.h>
using namespace std;

/*
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize 
consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, 
or false otherwise.

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

Link: https://leetcode.com/problems/hand-of-straights/description/
*/

bool isNStraightHand(vector<int>& hand, int groupSize) {
    unordered_map<int,int> mp;
    for(auto val:hand){
        mp[val]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto& it: mp){
        pq.push(it.first);
    }
    
    while(pq.empty()==false){
        vector<int> remaing_cards;
        int prev = pq.top();
        pq.pop();
        if(mp[prev]>1){
            mp[prev]--;
            remaing_cards.push_back(prev);
        }
        
        for(int i=0;i<groupSize-1; i++){
            int curr = pq.top();
            pq.pop();
            if(curr-prev!=1) {
                cout<<curr<<" "<<prev<<endl;
                return false;
            }
            prev=curr;
            if(mp[prev]>1){
                mp[prev]--;
                remaing_cards.push_back(prev);
            }
        }
        for(auto it:remaing_cards){
            pq.push(it);
        }
    }
    return true;        
}



int main() {
    // vector<int> hand = {1,2,3,6,2,3,4,7,8};
    // int groupSize = 3;
    vector<int> hand = {1,1,2,2,3,3};
    int groupSize = 2;
    cout<<isNStraightHand(hand, groupSize)<<endl;
    return 0;
}