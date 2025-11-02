#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;

        for(int i = 0; i < nums.size();i++){
            mp.insert(nums[i]);
        }
        int ans = 0;

        for(int t : mp){
            if(mp.find(t-1)==mp.end()){
                int curr = t;
                int cnt = 1;
                while(mp.find(curr+1)!=mp.end()){
                    curr++;
                    cnt++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};