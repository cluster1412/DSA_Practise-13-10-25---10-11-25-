#include<bits/stdc++.h>
using namespace std;

int nthFibonacci(int n) {
    if(n==1) return 1; 
    if(n==0) return 0;
    
    return nthFibonacci(n-1) + nthFibonacci(n-2);
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<n<<"th number of fibonacci is: "<<nthFibonacci(n);
    return 0;
}