#include <bits/stdc++.h>
using namespace std;

/*
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. 
You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel 
image[sr][sc].

To perform a flood fill:

1. Begin with the starting pixel and change its color to color.
2. Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally 
or vertically) and shares the same color as the starting pixel. 
3. Keep repeating this process by checking neighboring pixels of the 
updated pixels and modifying their color if it matches the original color of the starting pixel. 
4. The process stops when there are no more adjacent pixels of the original color to update. Return the modified image after performing the 
flood fill.

Link: https://leetcode.com/problems/flood-fill/description/

*/

void fill(vector<vector<int>>& image, int sr, int sc, int color, int n, int m, int oc){
    int deltaRow[] = {0,0,-1,1};
    int deltaCol[] = {-1,1,0,0};

    for(int i=0;i<4;i++){
        int row = sr+deltaRow[i];
        int col = sc+deltaCol[i];
        if(row>=0 && row<n && col>=0 && col<m && image[row][col]==oc){
            image[row][col]=color;
            fill(image, row, col, color, n, m, oc);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n=image.size();
    
    if(n==0)
        return image;
    int m = image[0].size();
    int oc = image[sr][sc];
    if(image[sr][sc]==color)
        return image;
    image[sr][sc]=color;
    fill(image, sr,sc,color,n,m, oc);
    return image;
}

int main() {

    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr=1;
    int sc=1;
    int color=2;
    cout<<"Before fill matrix is:\n";
    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[i].size();j++){
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
    floodFill(image,sr,sc,color);

    cout<<"After fill matrix is:\n";
    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[i].size();j++){
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }

    


    return 0;
}