#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {

        int m = fb.size();

        for(int i = 0 ; i < m ; i++){
            
            if(fb[i] == 0){
                bool l = (i == 0) ? 0 : fb[i-1];
                bool r = (i == m-1) ? 0 : fb[i+1];
                if(!l && !r){
                    --n;
                    fb[i] = 1;
                }
            }
        }
        return n <= 0;
    }
};