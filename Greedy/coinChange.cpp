#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& coins, int t,int idx,int& cnt,int c){
        if(idx == -1 || t < 0){
            return;
        }
        if(c>=cnt) return;
        if( t == 0 ){
            cnt = min(cnt,c);
            return;
        }
        if(t >= coins[idx]) solve(coins,t-coins[idx],idx,cnt,c+1);
        solve(coins,t,idx-1,cnt,c);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        int cnt = INT_MAX;
        solve(coins,amount,n-1,cnt,0);
        return cnt!=INT_MAX ? cnt : -1;
    }
};