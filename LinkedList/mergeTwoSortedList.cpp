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

node* mergeTwoLists(node* list1, node* list2) {

    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    node* list3 = new node(0);
    node* temp = list3;

    while(list1 != NULL && list2 != NULL){
        if(list1->d <= list2->d){
            temp->next = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            list2 = list2->next;
        }
        temp=temp->next;
    }
    while(list1!=NULL){
        temp->next = list1;
        temp = temp->next;
        list1 = list1->next;
    }
    while(list2!=NULL){
        temp->next = list2;
        temp = temp->next;
        list2 = list2->next;
    }

    return list3->next;
}

int main(){
    node* head = new node(-1);
    int n;
    cout<<"Enter number of nodes in a linked list 1: ";
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
    node* head1 = new node(-1);
    int n1;
    cout<<"\nEnter number of nodes in a linked list 2: ";
    cin>>n1;
    cout<<"Enter values of nodes: ";
    node* temp1 = head1;
    for(int i = 0; i<n1;i++){
        int x;
        cin>>x;
        temp1->next = new node(x);
        temp1 = temp1->next;
    }
    temp1 = head1;
    head1 = head1->next;
    delete temp1;
    cout<<"\nEntered linked list is: ";
    temp1 = head1;
    while(temp1){
        cout<<temp1->d;
        if(temp1->next) cout<<" -> ";
        temp1 = temp1->next;
    }
    head = mergeTwoLists(head,head1);
    cout<<"\nMerged linked list is: ";
    temp = head;
    while(temp){
        cout<<temp->d;
        if(temp->next) cout<<" -> ";
        temp=temp->next;
    }
    return 0;
}
