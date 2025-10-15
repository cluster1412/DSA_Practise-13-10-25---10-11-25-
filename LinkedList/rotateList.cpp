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

node* rotateRight(node* head, int k) {
    if(!head || !head->next || !k) return head;
    node* temp = head;
    int n = 0;
    while(temp){
        temp = temp->next;
        n++;
    }
    if(n==k) return head;
    k = k % n;
    if(!k) return head;
    n = n - k;

    temp = head;
    while(--n){
        temp = temp->next;
    }
    node* head1 = temp->next;
    node* temp1 = temp;

    while(temp->next){
        temp = temp->next;
    }
    temp -> next = head;
    temp1->next = nullptr;

    return head1;
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
    int k;
    cout<<"\nEnter value of k: ";
    cin>>k;
    head = rotateRight(head,k);
    cout<<"\nRotated linked list k times is: ";
    temp = head;
    while(temp){
        cout<<temp->d;
        if(temp->next) cout<<" -> ";
        temp=temp->next;
    }
    return 0;
}