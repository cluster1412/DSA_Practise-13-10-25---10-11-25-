#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int p = 0;
        if(nums.size() == 1 && target == nums[0]) return true;
        if(nums.size() == 1 && target != nums[0]) return false;
        while( s <= e ){
            if(nums[s] > nums[s+1]){
                p = s;
                break;
            }
            else if(nums[e]<nums[e-1]){
                p=e-1;
                break;
            }
            s++;e--;
        }

        s = 0 ; e = nums.size() - 1 ;

        if( target == nums[p]) return true;
        else if(target < nums[p] && target >= nums[0]) e = p-1;
        else s=p+1;

        while( s <= e ){
            int mid = s + (e-s)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) e= mid - 1;
            else s = mid + 1;
        }
        return false;
    }
};