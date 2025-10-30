#include<bits/stdc++.h>
using namespace std;

class myQueue {
    int *arr = nullptr;
    int rear = -1;
    int front = -1;
    int size = 0;
    int cnt = 0;
public:
    myQueue(int n) {
        // Define Data Structures
        arr = new int[n];
        size = n;
    }

    bool isEmpty() {
        // check if the queue is empty
        if(cnt == 0) return true;
        return false;
    }

    bool isFull() {
        // check if the queue is full
        if(cnt == size) return true;
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isEmpty()){
            arr[0] = x;
            rear=1;front=0;
            cnt++;
        }
        else if(!isFull()){
            arr[rear%size] = x;
            rear++;
            cnt++;
        }
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(!isEmpty()){
            arr[front] = -1;
            front++;
            front = front % size;
            cnt--;
        }
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty()) return -1;
        return arr[rear-1];
    }
};