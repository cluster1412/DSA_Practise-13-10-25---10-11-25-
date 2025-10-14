#include<bits/stdc++.h>
using namespace std;

void rotation(vector<int>& nums,int i ,int j){
    while(i < j){
        swap(nums[i++],nums[j--]);
    }
}

    void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    k = k % n;
    rotation(nums,0,n - 1);
    rotation(nums,0,k - 1);
    rotation(nums,k,n - 1);
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
    int k = 0;
    cout<<"\nEnter k: ";
    cin>>k;
    rotate(arr,k);

    cout<<"Right rotated array by k steps is: ";
    for(int i:arr){
        cout<<i<<" ";
    }

    return 0;
}