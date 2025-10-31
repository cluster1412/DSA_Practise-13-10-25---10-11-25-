#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlace(vector<int> &stalls, int k,int mid){
        int cows = 1;
        int i  = 1;
        int last = 0;
        while(i < stalls.size()){
            if(stalls[i] - stalls[last] >= mid){
                cows++;
                last = i;
            }
            i++;
        }
        if(cows >= k) return true;
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        
        sort(stalls.begin(),stalls.end());
        
        int s = 1;
        int e = *max_element(stalls.begin(),stalls.end()) - 
                *min_element(stalls.begin(),stalls.end());
        int ans = -1;
        while( s <= e ){
            int mid = s + (e-s)/2;
            
            if(canPlace(stalls,k,mid)){
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        return ans;
        
    }
};