#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size(),i=0;
    int m=nums2.size(),j=0;
    vector<int> ans;
    map<int,int> mp;
    while(i<m){
        mp[nums2[i]]=i;
        i++;
    }
    int top = mp[nums1[j]];
    while(j<n){
        if(top == m){
            j++;
            if(j==n) break;
            top = mp[nums1[j]] + 1;
            ans.push_back(-1);
        }
        else if( nums2[top++] > nums1[j]){
            ans.push_back(nums2[--top]);
            j++;
            if(j==n) break;
            top = mp[nums1[j]] + 1;
        }
    }
    if(ans.size()!=n) ans.push_back(-1);
    return ans;
}

int main(){
    int n,m;
    cout<<"Enter size of array 1: ";
    cin>>n;
    cout<<"Enter size of array 2: ";
    cin>>m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    cout<<"Enter array 1 elements: ";
    for(int i = 0 ; i < n ; i++){
        cin>>arr1[i];
    }
    cout<<endl;
    cout<<"Enter array 2 elements: ";
    for(int i = 0 ; i < m ; i++){
        cin>>arr2[i];
    }
    cout<<endl;
    vector<int> ans;
    ans = nextGreaterElement(arr1,arr2);
    cout<<"\nNext greater elements are: ";
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}