#include<bits/stdc++.h>
using namespace std;

int reverse(int n){
    int rev = 0;
    while(n){
        rev = rev*10 + n % 10;
        n=n/10;
    }
    return rev;
}
int power(int n, int rev){
    if(rev==0) return 1;
    return n*power(n,rev-1);
}
int reverseExponentiation(int n) {
    int rev = reverse(n);
    return power(n,rev);
}


int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<n<<" is to power "<<reverse(n)<<" is: "<<reverseExponentiation(n);
    return 0;
}