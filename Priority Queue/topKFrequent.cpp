#include<bits/stdc++.h>
using namespace std;

struct Compare{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second < b.second ? true : false;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        vector<int> ans;

        unordered_map<int,int> mp;

        for(int i : nums){
            mp[i]++;
        }

        for(auto& t : mp){
            pq.push({t.first,t.second});
        }

        while(k){
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }

        return ans;
    }
};