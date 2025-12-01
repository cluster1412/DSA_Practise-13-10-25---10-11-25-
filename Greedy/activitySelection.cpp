#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        
        vector<pair<int,int>> mp;
        
        int n = start.size();
        if(n==0) return 0;
        
        for(int i = 0 ; i < n ; i++){
            mp.push_back({finish[i],start[i]});
        }
        
        sort(mp.begin(),mp.end());
        
        int cnt = 1;
        int j = mp[0].first;
        
        for(int i = 1; i < n ; i++){
            if(j < mp[i].second){
                cnt++;
                j = mp[i].first;
            }
        }
        
        return cnt;
        
    }
};