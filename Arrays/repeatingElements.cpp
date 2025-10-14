#include<bits/stdc++.h>
using namespace std;

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
    
    sort(arr.begin(),arr.end());
    cout<<"Sorted array is :";
    for(int i = 0; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Elements that are repeating are: ";
    
    int j = 0,cnt = 1;
    
    for(int i = 1;i<n;i++){
        if(arr[i] != arr[i-1] && cnt > 1){
            cout<<arr[i-1]<<" ";
            cnt = 1;
        }
        else cnt++;
    }
    if(cnt>0) cout<<arr[n-1];
    
    return 0;
}