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

node* reverse(node* head){

    if(!head || !head->next) return head;

    node* nn = reverse(head->next);

    head->next->next = head;
    head->next = nullptr;
    return nn;
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
    head = reverse(head);
    cout<<"\nReversed linked list is: ";
    temp = head;
    while(temp){
        cout<<temp->d;
        if(temp->next) cout<<" -> ";
        temp=temp->next;
    }
    return 0;
}