#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int toggleBits(int n, int l, int r) {
        
        int x = n;
        string s = "";
        int i = 1;
        while(x){
            if((x&1) && i>=l && i <= r) s = "0" + s;
            else if((x&1)==0 && i>=l && i <= r) s = "1" + s;
            else if(x&1) s = "1" + s;
            else s = "0" + s;
            x = x >> 1;
            i++;
        }
        int size = s.size();
        int a = 0;
        int num = 0;
        for(int i = 0;i<size;i++){
            int cnt = pow(2,a)*(s[size-i-1]-'0');
            num += cnt;
            a++;
        }
        
        return num;
        
    }
};

/*
class Solution {
public:
    int toggleBits(int n, int l, int r) {
        
        int x = n;
        int mask = ((1<<(r-l+1))-1)<<(l-1);
        x=x^mask;
        return x;
    }
};
*/