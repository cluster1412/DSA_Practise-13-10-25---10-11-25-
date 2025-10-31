#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;

        for(int t : nums1) mp1[t]++;
        for(int t : nums2) mp2[t]++;

        vector<int> res;

        for(auto& it : mp1){
            if(mp2.count(it.first)>0)
                res.push_back(it.first);
        }
        
        return res;
    }
};