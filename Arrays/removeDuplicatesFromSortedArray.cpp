#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int j = 1;
    for(int i = 1 ; i < n ; i++){
        if(nums[i]==nums[i-1]) continue;
        nums[j++] = nums[i];
    }

    return j;
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
    
    sort(arr.begin(),arr.end());
    cout<<"Sorted array is :";
    for(int i = 0; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int k = removeDuplicates(arr);
    cout<<"New array is: ";
    for(int i = 0; i<k;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}