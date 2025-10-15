#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums,int s,int e,int mid){
    vector<int> temp;
    int i = s,j = mid+1;
    while(i<=mid && j<=e){
        if(nums[i]<=nums[j]){
            temp.push_back(nums[i]);
            i++;
        }
        else{
            temp.push_back(nums[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(nums[i]);
        i++;
    }
    while(j<=e){
        temp.push_back(nums[j]);
        j++;
    }
    int l = 0;
    for(int k = s;k<=e;k++){
        nums[k] = temp[l++];
    }
}

void mergeSort(vector<int>& nums,int s,int e){
    if(s>=e) return;
    int mid = s + (e-s)/2;
    mergeSort(nums,s,mid);
    mergeSort(nums,mid+1,e);
    merge(nums,s,e,mid);
}
int median(vector<vector<int>> &mat) {
    vector<int>temp;
    
    for(int i = 0;i<mat.size();i++){
        for(int j = 0; j<mat[0].size();j++){
            temp.push_back(mat[i][j]);
        }
    }
    int n = temp.size();
    mergeSort(temp,0,n-1);
    return temp[n/2];
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
    int ans = median(mat);
    cout<<"Median of matrix is: "<<ans;
    return 0;
}