#include<bits/stdc++.h>
using namespace std;

char maxFreq(string str){
    vector<int> ch(256);
    int n = str.size();

    int maxfreq = INT_MIN;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ch[str[i]]++;
        if (ch[str[i]] > maxfreq) {
            maxfreq = ch[str[i]];
            ans = str[i];
        }
    }
    return ans;
}

int main(){
    string s;
    cout<<"Enter a string: ";
    getline(cin,s);
    char ans = maxFreq(s);
    cout<<"Character having maximum frequency is: "<<ans;
    return 0;
}