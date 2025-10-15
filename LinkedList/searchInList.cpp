#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int d;
    node* next = nullptr;
    node(int v){
        this->d = v;
        this->next = nullptr;
    }
    ~node(){
        this->next = nullptr;
    }
};

bool found(node* head,int k){
    if(head==nullptr){
        return false;
    }
    if(head->d==k){
        return true;
    }
    return found(head->next,k);
}

int main(){
    node* head = new node(-1);
    int n;
    cout<<"Enter number of nodes in a linked list: ";
    cin>>n;
    cout<<"Enter values of nodes: ";
    node* temp = head;
    for(int i = 0; i<n;i++){
        int x;
        cin>>x;
        temp->next = new node(x);
        temp = temp->next;
    }
    temp = head;
    head = head->next;
    delete temp;
    cout<<"\nEntered linked list is: ";
    temp = head;
    while(temp){
        cout<<temp->d;
        if(temp->next) cout<<" -> ";
        temp=temp->next;
    }
    int t;
    cout<<"\nEnter a key to find: ";
    cin>>t;

    if(found(head,t)){
        cout<<"\nKey found";
    }
    else cout<<"\nKey not found";

    
    return 0;
}