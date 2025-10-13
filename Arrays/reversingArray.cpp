#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr , int m){
    int n = arr.size();
    int j = n-1;

    for(int i = m+1;i<j;i++){
        swap(arr[i],arr[j--]);
    }
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    cout<<"Entered array is :";
    for(int i = 0; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    int m;
    cout<<"\n\nEnter the index from which you want to reverse: ";
    cin>>m;
    reverseArray(arr,m);
    cout<<"\nReversed array is: ";
    for(int i = 0; i < n ; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}