#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i : arr){
            pq.push(i);
        }
        while(--k){
            pq.pop();
        }
        return pq.top();
    }
};