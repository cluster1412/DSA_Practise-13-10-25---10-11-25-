#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> ans;
    
    void solve(int i,vector<int>&arr,vector<int>&temp){
        ans.push_back(temp);
        
        for(int j = i;j<arr.size();j++){
            
            if(j >i && arr[j]==arr[j-1]) continue;
            
            temp.push_back(arr[j]);
            solve(j+1,arr,temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> findSubsets(vector<int>& arr) {
        sort(arr.begin(),arr.end());
       vector<int> temp;
       solve(0,arr,temp);
       return ans;
    }
};
