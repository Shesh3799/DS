#include <bits/stdc++.h>
using namespace std;

/*

*/
int kthSmallest(vector<int> &nums, int k) {
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(nums[i]);
    }
    for(int i=k;i<nums.size();i++){
        pq.push(nums[i]);
        pq.pop();
    }
    return pq.top();
}
int main() {

    vector<int> arr = {2, 3, 1, 20, 15};
    int k = 4;

    //Expected answer is 15
    cout<<kthSmallest(arr,k)<<endl;
    
    return 0;
}