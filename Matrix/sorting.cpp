#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums,int s,int e,int mid){
        vector<int> temp;
        int i = s,j = mid+1;
        while(i<=mid && j<=e){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=e){
            temp.push_back(nums[j]);
            j++;
        }
        int l = 0;
        for(int k = s;k<=e;k++){
            nums[k] = temp[l++];
        }
    }

    void mergeSort(vector<int>& nums,int s,int e){
        if(s>=e) return;
        int mid = s + (e-s)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,e,mid);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    int total = 0;
    cout<<"Entered array is :";
    for(int i = 0; i < n ; i++){
        cout<<arr[i]<<" ";
        total+= arr[i];
    }
    cout<<endl;
    mergeSort(arr,0,n-1);
    cout<<"Sorted array is: ";
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}