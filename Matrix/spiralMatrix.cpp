#include<bits/stdc++.h>
using namespace std;

void printSpiral(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        cout << "Matrix is empty." << endl;
        return;
    }

    int numRows = matrix.size();
    int numCols = matrix[0].size();
    
    int top = 0;
    int bottom = numRows - 1;
    int left = 0;
    int right = numCols - 1;

    cout << "Spiral Order: ";

    while (top <= bottom && left <= right) {

        for (int i = left; i <= right; ++i) {
            cout << matrix[top][i] << " ";
        }
        top++; 

        if (top <= bottom) {
            for (int i = top; i <= bottom; ++i) {
                cout << matrix[i][right] << " ";
            }
            right--; 
        }

        if (top <= bottom && left <= right) {
            for (int i = right; i >= left; --i) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--; 
        }

        if (top <= bottom && left <= right) {
            for (int i = bottom; i >= top; --i) {
                cout << matrix[i][left] << " ";
            }
            left++; 
        }
    }
    cout << endl;
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
    printSpiral(mat);
    return 0;
}