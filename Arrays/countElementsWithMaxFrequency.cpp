#include<bits/stdc++.h>
using namespace std;

int maxFrequencyElements(vector<int>& nums) {
        vector<int> a(101,0);
        for(int i : nums){
            a[i-1]++;
        }
        int ans = 0 , max = 0;

        for(int i = 0; i <= 100; i++){
            if(a[i] > max){
                max = a[i]; 
                ans = a[i];
            }
            else if(a[i] == max) 
                ans+=a[i];
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

    int ans = maxFrequencyElements(arr);
    cout<<"Number of elements with max frequency are "<< ans;
    
    return 0;
}