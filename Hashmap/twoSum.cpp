#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;

        mp[nums[0]] = 0;
        
        for(int i = 1; i < n; i++){
            int h = target - nums[i];
            if (mp.count(h)){
                return {mp[h],i};
            }
            else mp[nums[i]] = i;
        }
        return {};
    }
};