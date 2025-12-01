#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int i = 0, n = arr.size();
        int p = arr[0];
        while(i < n){
            p = max(p,arr[i]);
            if(i == p){
                ans++;
            }
            i++;
        }
        return ans;
    }
};