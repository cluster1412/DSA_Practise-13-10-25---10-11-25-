#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char getMaxOccuringChar(string& s) {
        vector<int> mp(26,0);
        int ans = 0;
        int mx = 0;
        
        for(char c : s){
            mp[c-'a']++;
        }

        for(int i = 0 ; i < 26 ;i++){
            if(mx < mp[i]){
                mx = mp[i];
                ans = i;
            }
        }
        return ans + 'a';
    }
};