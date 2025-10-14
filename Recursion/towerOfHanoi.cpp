#include<bits/stdc++.h>
using namespace std;

int towerOfHanoi(int n, int from, int to, int aux) {
    if(n<=0) return 0;
    int moves_to_n = towerOfHanoi(n-1,from,to,aux);
    return moves_to_n + 1 + moves_to_n;
}

int main(){
    
    return 0;
}