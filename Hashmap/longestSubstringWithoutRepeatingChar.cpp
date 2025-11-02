#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0, maxl = 0;
        int mp[256];
        for(int i = 0; i < 256; i++){
            mp[i] = -1;
        }
        while(r < n){
            if(mp[s[r]] != -1){
                l = max(mp[s[r]] + 1,l);
            }
            maxl = max(maxl,r-l+1);
            mp[s[r]] = r;
            r++;
        }
        return maxl;
    }
};