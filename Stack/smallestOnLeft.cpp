#include<bits/stdc++.h>
using namespace std;

vector<int> Smallestonleft(vector<int>& arr, int n) {
    vector<int> r(n,-1);
    set<int>s;
    for(int i=0;i<n;i++){
        auto it=s.lower_bound(arr[i]);
        if(it!=s.begin()){
            --it;
            r[i]=*it;
        }
        s.insert(arr[i]);
    }
    return r;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr1(n);
    cout<<"Enter array elements: ";
    for(int i = 0 ; i < n ; i++){
        cin>>arr1[i];
    }
    cout<<endl;
    vector<int> ans;
    ans = Smallestonleft(arr1,n);
    cout<<"\nSmallest on left are: ";
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}