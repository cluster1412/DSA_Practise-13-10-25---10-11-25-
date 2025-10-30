#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();

        int l=0,r=n-1,sum=0;
        int lm=0,rm=0;

        while(l<r){
            if(h[l] <= h[r]){
                if(lm <= h[l]) lm = h[l];
                sum += lm-h[l];
                l++;
            }
            else{
                if(rm <= h[r]) rm = h[r];
                sum += rm - h[r];
                r--;
            }
        }
        return sum;
    }
};