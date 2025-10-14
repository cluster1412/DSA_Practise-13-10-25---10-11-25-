#include<bits/stdc++.h>
using namespace std;

int evenlyDivides(int n) {
    int r = n;
    int d = 0;
    int cnt = 0;
    while(r>0){
        d = r % 10;
        if(d!=0)
        cnt += (n%d==0) ? 1 : 0;
        r /= 10;
    }
    return cnt;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Digits that divide the number are: "<<evenlyDivides(n);
    return 0;
}