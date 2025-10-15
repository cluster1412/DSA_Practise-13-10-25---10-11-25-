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

node* middleNode(node* head) {
        node* temp = head;
        int cnt = 0;
        while(temp!=NULL){
            cnt++;
            temp = temp -> next;
        }
        int src = cnt/2;
        int i=0;
        temp = head;
        while(i<src){
            temp=temp->next;
            i++;
        }
        return temp;
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
    head = middleNode(head);
    cout<<"\nMid linked list is: ";
    temp = head;
    while(temp){
        cout<<temp->d;
        if(temp->next) cout<<" -> ";
        temp=temp->next;
    }
    return 0;
}