#include <bits/stdc++.h>
using namespace std;

/*

*/

int findMin(vector<int>& arr) {
    int low = 0;
    int high = arr.size()-1;
    int min_so_far = INT_MAX;
    while(low<=high){
        int mid = low + (high-low)/2;
        //Left sorted
        if(arr[low]<=arr[mid]){
            min_so_far = min(min_so_far, arr[low]);
            low=mid+1;
        }
        else{
            min_so_far = min(min_so_far, arr[mid]);
            high=mid-1;
        }
    }
    return min_so_far;
}

int main() {
    vector<int> arr = {3,4,5,1,2};
    cout<<"Min is "<<findMin(arr)<<endl;
    

    return 0;
}