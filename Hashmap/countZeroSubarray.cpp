#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSubarray(vector<int> &arr) {
        
        unordered_map<int,int> mp;
        int ans = 0;
        int sum = 0;
        mp[0] = 1;
        for(int i = 0; i < arr.size() ; i++){
            sum += arr[i];
            if(mp.count(sum)){
                ans += mp[sum];
                mp[sum]++;
            }
            else{
                mp[sum] = 1;
            }
        }
        return ans;
    }
};