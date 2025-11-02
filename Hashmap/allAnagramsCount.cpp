#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();
        vector<int> ans;
        if(n < k) return ans;
        vector<int> mfreq(26,0);
        for(char c : p){
            mfreq[c-'a']++;
        }
        vector<int> freq(26,0);
        
        int i = 0, j = 0;

        while(j < n){
            freq[s[j]-'a']++;
            
            if(j-i+1==k){
                if(freq == mfreq){
                    ans.push_back(i);
                }
                freq[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};