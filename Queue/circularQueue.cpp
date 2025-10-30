#include<bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    vector<int> q;
    int front = -1;
    int rear = -1;
    int k=0;
    MyCircularQueue(int k) {
        this->k=k;
        q.resize(k);
    }
    
    bool enQueue(int value) {
        if(isEmpty()){
            q[0] = value;
            front++;
            rear++;
            return true;
        }
        else if(!isFull()){
            if(rear < q.size()-1){
                rear++;
                q[rear]=value;
            }
            else{
                rear=0;
                q[rear] = value;
            }
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!isEmpty()){
            if(front == rear){
                front=-1;
                rear=-1;
            }
            else if(front == q.size()-1){
                front = 0;
            }
            else front++;;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        if(front == -1 && rear == -1) return true;
        return false;
    }
    
    bool isFull() {
        if(rear-front+1 == q.size() || front-1 == rear) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */