#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m=matrix.size(),
        n=matrix[0].size(),
        i=0,j=n-1;
    while( i < m && j > -1 ){

        int h = matrix[i][j];
        
        if (h == target) return true;
        
        if (h < target) i++;
            
        else j--;
    }
    return false;
}

int main(){
    int n,m;
    cout<<"Enter no. of rows: ";
    cin>>n;
    cout<<"Enter no. of cols: ";
    cin>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    cout<<"Enter elements: ";
    for(int i = 0; i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int t;
    cout<<"\nEnter target to search: ";
    cin>>t;
    if(searchMatrix(mat,t)) cout<<"Element found !!!";
    else cout<<"Element Not Found !!!";
    return 0;
}