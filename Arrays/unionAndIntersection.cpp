#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    set<int> res;
    vector<int> ans;
    int i = 0, j = 0;

    while(i < nums1.size() && j < nums2.size()) {
        if(nums1[i] == nums2[j]){
            res.insert(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i] > nums2[j]) j++;
        else i++;
    }
    for(int k: res){
        ans.push_back(k);
    }

    return ans;
}

void unio(vector<int>& nums1, vector<int>& nums2){
    for(int i : nums2){
        nums1.push_back(i);
    }

    sort(nums1.begin(),nums1.end());
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
    ans = intersection(arr1,arr2);
    cout<<"intersection array is :";

    for(int i = 0; i < ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    unio(arr1,arr2);
    cout<<"union array is :";

    for(int i = 0; i < arr1.size() ; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

    return 0;
}