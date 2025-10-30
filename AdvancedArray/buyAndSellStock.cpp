#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=prices[0],p=0;

        for(int i=0; i<n; i++){

            if(buy>prices[i]) buy=prices[i];
            p=max(p,prices[i]-buy);
        }
        return p;
    }
};