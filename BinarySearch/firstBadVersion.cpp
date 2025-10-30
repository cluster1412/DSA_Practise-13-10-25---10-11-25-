#include<bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // temporary function 
    bool isBadVersion(int n){
        return n%2?1:0;
    }
    int firstBadVersion(int n) {
        int s = 1, e = n;
        int ans = 0;

        while(s<=e){

            int mid = s + (e-s) /2;

            if(isBadVersion(mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return ans;
    }
};