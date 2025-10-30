#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0, e=height.size()-1,vol=0;
        while(s<e){
            vol = max(vol,min(height[s],height[e]) * (e-s));
            if(height[s]>height[e]) e--;
            else s++;
        }
        return vol;
    }
};