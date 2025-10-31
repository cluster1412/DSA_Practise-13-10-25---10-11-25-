#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        int ans = 0;

        for(int i = 0; i < n ; i++){
            mp[nums[i]] = i;
        }

        for(auto& it : mp){
            if(ans == it.first) ans++;
            else return ans;
        }
        return ans;
    }
};