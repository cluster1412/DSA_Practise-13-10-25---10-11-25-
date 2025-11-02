#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> cnts(26,0);
        vector<int> cntg(26,0);

        int x = 0;
        int y = 0;

        for(int i = 0; i < secret.size();i++){
            if(secret[i]==guess[i]) 
                x++;
            cnts[secret[i]-'0']++;
            cntg[guess[i]-'0']++;
        }

        for(int i = 0;i<26;i++)
            if(cnts[i] > 0 && cntg[i] > 0)
                y += min(cnts[i],cntg[i]);

        return to_string(x)+"A"+to_string(y-x)+"B";
    }
};