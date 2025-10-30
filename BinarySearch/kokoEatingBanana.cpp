#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getHours(vector<int>& piles, long long h){
        long long cnt = 0;
        for(int i : piles){
            cnt += i/h;
            if(i%h) cnt++;
        }
        return cnt;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int s = 1, e = *max_element(piles.begin(),piles.end());
        int ans = e;

        while(s<=e){

            int mid = s+(e-s)/2;
            long long hours = getHours(piles,mid);

            if(hours <= h) {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};