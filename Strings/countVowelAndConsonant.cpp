#include<bits/stdc++.h>
using namespace std;

void count(string str){
    int n = str.size();

    for(int i = 0; i<n ;i++){
        str[i] = towlower(str[i]);
    }
    int vowel=0,consonant = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            vowel++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z'){
            consonant++;
        }
    }
    cout << "Vowels: " << vowel << "\n";
    cout << "Consonants: " << consonant << "\n";
}
int main(){
    string s;
    cout<<"Enter a string: ";
    getline(cin,s);

    count(s);
    return 0;
}