#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int pre = 1, suf = 1;;
    int max_pro = INT_MIN;

    for(int i=0;i<n;i++){
        if(!pre) pre = 1;
        if(!suf) suf = 1;

        pre *= nums[i];
        suf *= nums[n - i - 1];

        max_pro = max(max_pro,max(pre,suf));
    }
    return max_pro;
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

    cout<<"max subarray product is: "<<maxProduct(arr);
    return 0;
}