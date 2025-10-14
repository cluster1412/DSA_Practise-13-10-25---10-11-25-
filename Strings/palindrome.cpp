#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
        int n = s.size();
        string s1="";
        for(int i=0;i<n;i++){
            if(s[i]>=97 && s[i]<=122){
                s1+=s[i];
            }
            else if(s[i]>=65 && s[i]<=90){
                s1+=s[i]-'A'+97;
            }
            else if(s[i]>=48 && s[i]<=57){
                s1+=s[i];
            }
        }
        int n1=s1.size();
        if(n1==0 || n1==1) return true;
        int i=0;
        int j=n1-1;
        while(i<j){
            if(s1[i]!=s1[j]) return false;
            i++;
            j--;
        }
        return true;
    }

int main(){
    string s;
    cout<<"Enter a string: ";
    getline(cin,s);
    cout<<endl;
    if(isPalindrome(s)) cout<<"Yes";
    else cout<<"No";
    return 0;
}