#include<bits/stdc++.h>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    map<int,int> mp;
    for(int i = 0;i<mat.size();i++){
        int cnt = 0;
        for(int j = 0;j<mat[0].size();j++){
            if(mat[i][j]) cnt++;
        }
        mp[i] = cnt;
    }
    vector<int> temp(2);
    int c = 0;
    for(int i = 0;i<mat.size();i++){
        if(mp[i] > c){
            c = mp[i];
            temp[0] = i;
            temp[1] = mp[i];
        }
    }
    return temp;
}

int main(){
    int n,m;
    cout<<"Enter no. of rows: ";
    cin>>n;
    cout<<"Enter no. of cols: ";
    cin>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    cout<<"Enter elements 0 or 1: ";
    for(int i = 0; i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<int> temp(2);
    temp = rowAndMaximumOnes(mat);
    for(int i = 0;i<2;i++) cout<<temp[i]<<" ";
    return 0;
}