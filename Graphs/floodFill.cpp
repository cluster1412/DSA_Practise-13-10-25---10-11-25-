#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void flipk(vector<vector<int>>& grid,int i,int j,int c,int o){
        grid[i][j] = c;
        if(i > 0 && grid[i-1][j] == o)
            flipk(grid,i-1,j,c,o);
        //right
        if(i+1 < grid.size() && grid[i+1][j]==o)
            flipk(grid,i+1,j,c,o);
        //top
        if(j > 0 && grid[i][j-1]==o)
            flipk(grid,i,j-1,c,o);
        //down
        if(j+1 < grid[0].size() && grid[i][j+1]==o)
            flipk(grid,i,j+1,c,o);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        flipk(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};