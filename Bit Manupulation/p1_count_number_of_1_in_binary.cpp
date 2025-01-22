#include <bits/stdc++.h>
using namespace std;

/*
Given a positive integer n, write a function that returns the number of 
set bits
 in its binary representation (also known as the Hamming weight).

 

Example 1:

Input: n = 11

Output: 3

Explanation:

The input binary string 1011 has a total of three set bits.

Link: https://leetcode.com/problems/number-of-1-bits/description/
*/

int hammingWeight(int n) {
    int count = 0;
    while(n){
        n=n&(n-1);
        count++;
    }
    return count;
}

int main() {
    cout<<"Number of 1's in binary representation of 11 is "<<hammingWeight(11)<<endl;

    return 0;
}