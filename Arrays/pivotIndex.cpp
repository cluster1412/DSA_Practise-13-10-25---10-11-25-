#include<bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
    int l_sum=0;
    for(int i=0;i<n;i++){
        sum-=nums[i];
        if(l_sum==sum) return i;
        l_sum+=nums[i];
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

    cout<<"Pivot index is: "<<pivotIndex(arr);

    return 0;
}