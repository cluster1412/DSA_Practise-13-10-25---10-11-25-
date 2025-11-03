#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkKthBit(int n, int k) {
        while(k--) n = n>>1;
        return n&1;
    }
};