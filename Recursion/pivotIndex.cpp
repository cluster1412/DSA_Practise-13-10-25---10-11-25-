#include<bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& arr,int i,int l,int total){
    if(i==arr.size()) return -1;
    if(l == total - l - arr[i]) return i;
    return pivotIndex(arr,i+1,l+arr[i],total);
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    int total = 0;
    cout<<"Entered array is :";
    for(int i = 0; i < n ; i++){
        cout<<arr[i]<<" ";
        total+= arr[i];
    }
    cout<<endl;

    cout<<"Pivot index is: "<<pivotIndex(arr,0,0,total);
    return 0;
}