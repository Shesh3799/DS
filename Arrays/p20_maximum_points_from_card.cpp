#include <bits/stdc++.h>
using namespace std;

/*

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. 
The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

Input: cardPoints = [100,40,17,9,73,75], k = 3
Output: 248
Explanation: Pick 1 card from index 0 and two cards from n-1 and n-2. i.e 100+75+73 = 248

Tags: Sliding Window

Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
*/

//We can pick k elements from the front or from the end not in between
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size(); 
    // We need to take k cards if n is less we won't be able to take k cards
    if(k>n) return 0;

            
    int leftSum = 0, max_sum=0, low = 0;

    //Pick first k cards
    for(int i=0; i<k && i<n; i++){
        leftSum+=cardPoints[i];
    }
    max_sum=leftSum;

    //Pick the cards from right end now
    int end = n-1;
    for(int i=k-1; i>=0;i--){
        //Remove k-1 element
        leftSum-=cardPoints[i];
        //Add n-1 element
        leftSum+=cardPoints[end--];
        max_sum=max(max_sum, leftSum);
    }
    return max_sum;
}


int main() {
    vector<int> arr = {100,40,17,9,73,75};

    int k = 3;

    cout<<"Maximum points : "<<maxScore(arr, k);

    return 0;
}