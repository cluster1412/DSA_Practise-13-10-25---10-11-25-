#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n=nums.size();
    int s=1;
    sort(nums.begin(),nums.end());
    for(int i=1;i<n;i++){
        if(nums[i]==nums[i-1]) s++;
        else{
            if(s>(n/2)) return nums[i-1];
            s=1;
        }
    }
    return nums[n-1];
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

    cout<<"majority element is: "<<majorityElement(arr);
    return 0;
}