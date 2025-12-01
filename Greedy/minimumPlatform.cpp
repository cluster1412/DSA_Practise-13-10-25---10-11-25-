#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int n = arr.size();
        int i = 0 , j = 0;
        
        int cnt = 0 , mcnt = 0;
        
        while(i < n && j < n){
            if(arr[i] <= dep[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            
            mcnt = max(mcnt,cnt);
        }
        
        return mcnt;
    }
};
