#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZero(vector<vector<int>>& matrix,int row,int col){

        for(int i = 0; i < matrix[0].size();i++)
            matrix[row][i] = 0;

        for(int i = 0; i < matrix.size();i++)
            matrix[i][col] = 0;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_multimap<int,int> mp;

        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++)
                if(matrix[i][j]==0)
                    mp.insert({i,j});
        }

        for(auto& it : mp)
            setZero(matrix,it.first,it.second);
    }
};