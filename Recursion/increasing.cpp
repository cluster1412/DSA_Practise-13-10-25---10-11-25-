#include<bits/stdc++.h>
using namespace std;

void printTillN(int n) {
    if(n==0) return;
    printTillN(n-1);
    cout<<n<<" ";
}
void printfromN(int n) {
    if(n==0) return;
    cout<<n<<" ";
    printfromN(n-1);
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<endl;
    cout<<"Increasing: ";
    printTillN(n);
    cout<<"\n";
    cout<<"Decreasing: ";
    printfromN(n);
    cout<<"\n";
    return 0;
}