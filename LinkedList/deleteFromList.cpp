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

void del(node*& head,int pos,int n){
    if(pos==1){
        node* temp=head;
        head = head->next;
        delete temp;
    }
    else if(pos>n){
        cout<<"Invalid position\n";
    }
    else{
        int cnt = 1;
        node* temp = head;
        while(cnt < pos-1){
            temp=temp->next;
            cnt++;
        }
        node * t = temp->next;
        temp->next = temp->next->next;
        delete t;
    }
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
    cout<<"\nEnter position of a node to delete: ";
    cin>>t;

    del(head,t,n);

    cout<<"\nNew linked list is: ";
    temp = head;
    while(temp){
        cout<<temp->d;
        if(temp->next) cout<<" -> ";
        temp=temp->next;
    }

    return 0;
}