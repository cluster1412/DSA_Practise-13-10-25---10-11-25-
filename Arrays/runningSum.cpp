#include<bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);

        ans[0] = nums[0];

        for(int i = 1 ; i < n ; i++){
            ans[i] = nums[i] + ans[i-1];
        }
        return ans;
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


    vector<int> ans;
    ans = runningSum(arr);

    cout<<"Running sum of array is ";
    for(int i = 0; i< n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}