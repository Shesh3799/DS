#include <bits/stdc++.h>
using namespace std;

class Point
{
    public:
    int x;
    int y;
};

struct Comparator {
    bool operator()(const Point& a, const Point& b) const {
        return a.x > b.x; // Modify comparison logic as needed
    }
};

bool grater(int &a, int &b){
    return a>b;
}

int main() {
    
    priority_queue<Point, vector<Point>, Comparator> pq;
    Point points[]={{1,2},{4,3},{2,2},{3,4}};
    for (int i = 0; i < 4; i++)
    {
        pq.push(points[i]);
    }
    while(pq.empty()==false){
        cout<<pq.top().x<<","<<pq.top().y<<endl;
        pq.pop();
    }

    vector<int> arr = {1,5,2,7,4};

    sort(arr.begin(),arr.end(),grater);

    for(auto x : arr){
        cout<<x<<" ";
    }
    cout<<endl;

    vector<pair<int,int>> distance = {{0,-1},{0,1},{-1,0},{1,0}};
    for(int i=0; i<distance.size(); i++){
            int nrow=distance[i].first;
            int ncol=distance[i].second;
            cout<<nrow<<" "<<ncol<<endl;
    }

    return 0;
}