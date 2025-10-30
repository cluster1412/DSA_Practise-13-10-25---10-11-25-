#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int search(vector<int>& nums, int t) {
        int n = nums.size();
        int s = 0, e = n - 1, mid = s + (e - s) / 2;

        while(s<e){
            // p = s;
            if(nums[mid] >= nums[0]){
                s = mid + 1;
            }
            else e = mid ;
            mid = s + (e-s)/2;
        }
        int  p = nums[s]<nums[0]? s : 0;
        s=0;
        e=n-1;

        if(t > nums[p] && nums[e]<t) e = p-1;
        else s = p;
        // cout<<p;
        mid= s + (e-s)/2;
        while(s<=e){
            if(nums[mid]==t){
                return mid;
            }
            
            else if(nums[mid] > t)
                e = mid - 1;

            else if(nums[mid] < t) 
                s = mid + 1;
            
            mid = s + (e -s) / 2;
        }

        return -1;
    }
};