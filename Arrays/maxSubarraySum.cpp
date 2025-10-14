#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int curr_sum = 0;
    int max_sum = INT_MIN;

    for(int i = 0; i < n; i++){
        curr_sum += nums[i];
        
        if(curr_sum > max_sum){
            max_sum = curr_sum;
        }
        
        if(curr_sum < 0){
            curr_sum = 0;
        }
    }
    return max_sum;
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
    cout<<"max subarray sum is: "<<maxSubArray(arr);
    return 0;
}