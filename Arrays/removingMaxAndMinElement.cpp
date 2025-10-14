#include<bits/stdc++.h>
using namespace std;

int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX;
        int mx = INT_MIN;
        int mn_idx=0,mx_idx=0;
        for(int i = 0; i < n ; i++){
            if(nums[i] < mn){
                mn = nums[i];
                mn_idx = i;
            }
            if(nums[i] > mx){
                mx = nums[i];
                mx_idx = i;
            }
        }
        
        if(mn_idx > mx_idx) swap(mn_idx,mx_idx);

        int front = mx_idx + 1;
        int back = n - mn_idx;
        int both = mn_idx + 1 + n - mx_idx;

        return min({front,back,both});
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
    int ans = minimumDeletions(arr);
    cout<<"Minimum Deletion are : "<<ans<<endl;

    return 0;
}