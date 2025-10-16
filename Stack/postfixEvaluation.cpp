#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(vector<string> &arr){
    stack<int> st;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] != "+" && arr[i] != "-" && arr[i] != "*" && arr[i] != "/" &&
            arr[i] != "^"){
            st.push(stoi(arr[i]));
        }
        else{
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (arr[i] == "+")
                st.push(b + a);
            else if (arr[i] == "-")
                st.push(b - a);
            else if (arr[i] == "*")
                st.push(b * a);
            else if (arr[i] == "/"){
                int res = b / a;
                if ((b ^ a) < 0 && b % a != 0)
                    res--; // adjust for floor division
                st.push(res);
            }
            else if (arr[i] == "^")
                st.push((int)pow(b, a));
        }
    }

    return st.top();
}

int main(){
    int n;
    cout<<"Enter size of expression: ";
    cin>>n;

    vector<string> st(n);
    cout<<"Enter elements: ";
    for(int i = 0; i<n;i++){
        cin>>st[i];
    }

    cout<<"Answer of expression is: "<<evaluatePostfix(st);
    return 0;
}
