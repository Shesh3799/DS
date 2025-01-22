#include <bits/stdc++.h>
using namespace std;

/*
You have been given 'N' ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their 
lengths. We need to connect the ropes with minimum cost.

4
4 3 2 6
Sample Output 1:
29
Explanation:
1) If we first connect ropes of lengths 2 and 3, we will left with three ropes of lengths 4, 6 and 5.

2) Now then, if we connect ropes of lengths 4 and 5, we will left with two ropes of lengths 6 and 9.

3) Finally, we connect the remaining two ropes and all ropes are now connected.

Total cost for connecting all ropes in this way is 5 + 9 + 15 = 29  which is the optimized cost.

Link: https://www.naukri.com/code360/problems/connect-n-ropes-with-minimum-cost_630476
*/
long long connectRopes(vector<int>&arr, int n)
{
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    long long cost=0;
    while(pq.size()>1){
        long long rope1= pq.top();
        pq.pop();
        long long rope2= pq.top();
        pq.pop();
        long long sum = rope1+rope2;
        cost+=sum;
        pq.push(sum);
    }
    return cost;
}

int main() {
    vector<int> arr = {4, 3, 2, 6};
    //Expected output = 29
    cout<<connectRopes(arr, arr.size())<<endl;

    return 0;
}