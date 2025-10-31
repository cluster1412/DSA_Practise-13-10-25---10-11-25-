#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;

        for(char c : s){
            mp[c]++;
        }
        for(char c : t){
            mp[c]--;
        }

        for(auto& t : mp){
            if(t.second!=0) return false;
        }
        return true;
    }
};