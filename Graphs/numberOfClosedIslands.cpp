#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void flipk(vector<vector<int>>& grid,int i,int j){
        grid[i][j]=1;
        if(i > 0 && grid[i-1][j]==0)
            flipk(grid,i-1,j);
        //right
        if(i+1 < grid.size() && grid[i+1][j]==0)
            flipk(grid,i+1,j);
        //top
        if(j > 0 && grid[i][j-1]==0 )
            flipk(grid,i,j-1);
        //down
        if(j+1 < grid[0].size() && grid[i][j+1]==0)
            flipk(grid,i,j+1);
    }
    void flip(vector<vector<int>>& grid,vector<vector<bool>>& vis,int i,int j){
        vis[i][j] = true;
        //left
        if(i-1 > 0 && grid[i-1][j]==0 && vis[i-1][j]==false)
            flip(grid,vis,i-1,j);
        //right
        if(i+1 < grid.size()-1 && grid[i+1][j]==0 && vis[i+1][j]==false)
            flip(grid,vis,i+1,j);
        //top
        if(j-1 > 0 && grid[i][j-1]==0 && vis[i][j-1]==false)
            flip(grid,vis,i,j-1);
        //down
        if(j+1 < grid[0].size()-1 && grid[i][j+1]==0 && vis[i][j+1]==false)
            flip(grid,vis,i,j+1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(grid[i][j] == 0)
                    flipk(grid,i,j);
                } 

        vector<vector<bool>> vis(n,vector<bool>(m));
        int cnt = 0;
        for(int i = 1 ; i < n-1 ; i++)
            for(int j = 1 ; j < m-1 ; j++)
                if(grid[i][j] == 0 && vis[i][j]==false){
                    flip(grid,vis,i,j);
                    cnt++;
                }

        return cnt;
    }
};