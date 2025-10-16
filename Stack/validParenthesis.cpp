#include <bits/stdc++.h>
using namespace std;

bool isValid(string s){
    stack<char> num;
    for (int c = 0; c < s.size(); c++){
        int n = num.size();
        if (s[c] == 40 || s[c] == 123 || s[c] == 91){
            num.push(s[c]);
            continue;
        }
        if (s[c] == 41 && n != 0 && num.top() == 40)
            num.pop();
        else if (s[c] == 125 && n != 0 && num.top() == 123)
            num.pop();
        else if (s[c] == 93 && n != 0 && num.top() == 91)
            num.pop();
        else
            return false;
    }
    return num.empty();
}

int main(){
    string s;
    cout<<"Enter a string of parenthesis: ";
    getline(cin,s);

    if(isValid(s)) cout<<"\nThe string is valid.";
    else cout<<"\nThe string is not valid.";
    return 0;
}