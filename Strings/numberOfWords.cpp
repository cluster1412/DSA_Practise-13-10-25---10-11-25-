#include<bits/stdc++.h>
using namespace std;

int countWords(string s){
    int cnt = 1;
    
    for(char i : s)
        if(i==' ')
            cnt++;
    
    return cnt;
}

int main(){
    string s;
    cout<<"Enter a string: ";
    getline(cin,s);
    
    cout<<"Number of words are: "<<countWords(s);
    return 0;
}