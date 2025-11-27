#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlace(vector<string>& board,int i,int j,int n){
        for(int k = 0;k<i;k++){
            if(board[k][j]=='Q') return false;
        }
        for(int k = i-1,l = j-1;k>=0 && l>=0; k--,l--){
            if(board[k][l]=='Q') return false;
        }
        for(int k = i-1,l = j+1;k>=0 && l < n; k--,l++){
            if(board[k][l]=='Q') return false;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans,int n,vector<string>& board,int i){
        if(i==n){
            ans.push_back(board);
            return;
        }
        for(int idx = 0;idx < n;idx++){
            if(canPlace(board,i,idx,n)){
                board[i][idx]='Q';
                solve(ans,n,board,i+1);
                board[i][idx] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,"");

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                board[i].push_back('.');
            }
        }
        solve(ans,n,board,0);
        return ans;
    }
};