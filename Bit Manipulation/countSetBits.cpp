#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPowerOf2(int n){
        int x = 0;
        while((1<<x) <= n) x++;
        return x-1;
    }
    int countSetBits(int n) {
        if(n==0) return 0;
        
        int x = largestPowerOf2(n);
        int bpo2 = pow(2,x);
        
        int prev = x * pow(2,x-1);
        int msb = n - bpo2 + 1;
        int rest = n - bpo2;
        
        return prev + msb + countSetBits(rest);
    }
};
