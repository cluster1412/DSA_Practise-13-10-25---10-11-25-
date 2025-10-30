#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s;
    stack<int> s1;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        while(!s.empty()){
            int t = s.top();
            s.pop();
            s1.push(t);
        }
        int k = s1.top();
        s1.pop();
        while(!s1.empty()){
            int t = s1.top();
            s1.pop();
            s.push(t);
        }
        return k;
    }
    
    int peek() {
        while(!s.empty()){
            int t = s.top();
            s.pop();
            s1.push(t);
        }
        int k = s1.top();
        while(!s1.empty()){
            int t = s1.top();
            s1.pop();
            s.push(t);
        }
        return k;
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */