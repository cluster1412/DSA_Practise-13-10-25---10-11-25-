#include<bits/stdc++.h>
using namespace std;

int sum(vector<int>& arr,int i){
    if(i==arr.size()) return 0;
    return arr[i] + sum(arr,i+1);
}
int arraySum(vector<int>& arr) {
    return sum(arr,0);
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    cout<<"Entered array is :";
    for(int i = 0; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Sum of array is: "<<arraySum(arr);
    return 0;
}