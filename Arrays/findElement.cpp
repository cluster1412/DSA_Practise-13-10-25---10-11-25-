#include<bits/stdc++.h>
using namespace std;

int pos(vector<int> arr,int ele){
    int n = arr.size();

    for(int i = 0; i<n; i++){
        if(ele == arr[i]) return i+1;
    }
    return -1;
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
    cout<<endl;
    int ele = 0;
    cout<<"Enter element to search in array: ";
    cin>>ele;

    cout<<"Element found at position: "<<pos(arr,ele);
    return 0;
}