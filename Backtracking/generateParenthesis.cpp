#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<string>& ans,string& res,int n,int no,int nc){
        if(res.size() == n*2){
            ans.push_back(res);
            return;
        }
        if (no < n) {
            res.push_back('(');
            solve(ans, res, n, no + 1, nc);
            res.pop_back();
        }
        if (nc < no) {
            res.push_back(')');
            solve(ans, res, n, no, nc + 1);
            res.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string res="";
        solve(ans,res,n,0,0);
        return ans;
    }
};