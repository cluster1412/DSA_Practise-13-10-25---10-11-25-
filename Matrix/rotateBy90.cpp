#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ; j++){
                if(i<j) swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2 ;j++){
                swap(matrix[i][j],matrix[i][n-j-1]);
            }
        }
    }

int main(){
    int n,m;
    cout<<"Enter no. of rows and cols: ";
    cin>>n;
    vector<vector<int>> mat(n,vector<int>(n));
    cout<<"Enter elements: ";
    for(int i = 0; i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    cout<<"Entered matrix is :"<<endl;
    for(int i = 0; i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    rotate(mat);
    cout<<"\nRotated matrix is :"<<endl;
    for(int i = 0; i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}