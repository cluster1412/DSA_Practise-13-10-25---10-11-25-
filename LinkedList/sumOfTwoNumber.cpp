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

node* addTwoNumbers(node* l1, node* l2) {
    node* dummyHead = new node(0);
    node* tail = dummyHead;
    int carry = 0;

    while (l1 || l2 || carry != 0) {
        int digit1 = (l1 != nullptr) ? l1->d : 0;
        int digit2 = (l2 != nullptr) ? l2->d : 0;

        int sum = digit1 + digit2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        node* newNode = new node(digit);
        tail->next = newNode;
        tail = tail->next;

        l1 = (l1 != nullptr) ? l1->next : nullptr;
        l2 = (l2 != nullptr) ? l2->next : nullptr;
    }

    node* result = dummyHead->next;
    delete dummyHead;
    return result;
}

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

    head = addTwoNumbers(reverse(head),reverse(head1));
    cout<<"\nSum of both linked list is: ";
    head=reverse(head);
    temp = head;
    while(temp){
        cout<<temp -> d;
        if(temp -> next) cout<<" -> ";
        temp = temp->next;
    }
    return 0;
}
