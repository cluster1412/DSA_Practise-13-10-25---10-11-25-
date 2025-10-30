#include<limits.h>
class MinStack {
public:
    int* st = nullptr;
    int toop = -1;
    MinStack() {
        st = new int[100000];
    }
    
    void push(int val) {
        st[++toop] = val;
    }
    
    void pop() {
        toop--;
    }
    
    int top() {
        return st[toop];
    }
    
    int getMin() {
        int m = INT_MAX;
        for(int i = 0;i<=toop;i++){
            if(st[i]< m) m = st[i];
        }
        return m;
    }
};
