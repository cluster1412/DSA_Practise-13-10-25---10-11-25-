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

void push(node*& head,int pos,int num,int n){
    if(pos == 1){
        node * temp = new node(num);
        temp->next = head;
        head = temp;
        return;
    }
    else if(pos == n+1){
        node* temp = head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next = new node(num);
        return;
    }
    else{
        int cnt = 1;
        node* temp = head;
        node* t = new node(num);
        while(cnt < pos-1){
            temp=temp->next;
            cnt++;
        }
        t->next = temp->next;
        temp->next = t;
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
    int pos = 0;
    int num = 0;
    cout<<"\nEnter a position: ";
    cin>>pos;
    cout<<"Enter a number: ";
    cin>>num;
    
    push(head,pos,num,n);
    cout<<"\nNew linked list is: ";
    temp = head;
    while(temp){
        cout<<temp->d;
        if(temp->next) cout<<" -> ";
        temp=temp->next;
    }

    return 0;
}