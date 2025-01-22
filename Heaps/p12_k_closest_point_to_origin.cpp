#include <bits/stdc++.h>
using namespace std;

/*

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).


Link: https://leetcode.com/problems/k-closest-points-to-origin/submissions/1480195754/
*/

long long distance_from_origin(int x1, int y1){
    //We know that x2 and y2 in our case is 0,0
    //We can return (x1^2 + y1^2) as result 
    return x1 * x1 + y1 * y1;

}
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<long long, pair<int,int>>, vector<pair<long long, pair<int,int>>>, greater<pair<long long, pair<int,int>>>> pq;
    for(int i=0; i<points.size(); i++){
        int dist = distance_from_origin(points[i][0],points[i][1]);
        pq.push(make_pair(dist, make_pair(points[i][0],points[i][1])));
    }
    vector<vector<int>> result;
    
    while(k>0){
        auto top = pq.top();
        pq.pop();
        result.push_back({top.second.first, top.second.second});
        k--;
    }
    return result;
}

int main() {
    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    int k = 2;
    vector<vector<int>> result = kClosest(points, k);
    //Expected Output: [[3,3],[-2,4]]
    for(auto& it: result){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    return 0;
}