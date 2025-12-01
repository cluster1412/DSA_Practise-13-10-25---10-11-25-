#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0; i<=8;i++){
            if(board[i][col] == c){
                return false;
            }
            if(board[row][i] == c) return false;

            if(board[3 * (row/3) + i/3][3*(col/3) + i%3]==c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board,int i,int j){
        if(i <= 8 && j > 8){
            j = 0;
            i++;
        }
        if(i > 8) return true;

        if(board[i][j]=='.'){

            for(char c = '1' ; c <= '9' ; c++){
                if(isValid(board,i,j,c)){
                    board[i][j] = c;
                    if(solve(board,i,j+1)){
                        return true;
                    }
                    else board[i][j] = '.';
                }
            }
            return false;
        }
        else{
            return solve(board,i,j+1);
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};