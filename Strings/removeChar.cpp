#include<bits/stdc++.h>
using namespace std;

string removeChar(string s){
    string s1 ="";

    for(char i:s){
        if(i>='a' && i<='z')
            s1+=i;
    }

    return s1;
}

int main(){
    string s;
    cout<<"Enter a string: ";
    getline(cin,s);

    string s1 = removeChar(s);

    cout<<s1;

    return 0;
}