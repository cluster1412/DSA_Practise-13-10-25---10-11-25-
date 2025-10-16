#include <bits/stdc++.h>
using namespace std;

#define STACK_MAX_SIZE 101
char stackArray[STACK_MAX_SIZE];
int stackTop = -1;

bool isStackEmpty() {
    return stackTop == -1;
}

bool isStackFull() {
    return stackTop >= STACK_MAX_SIZE - 1;
}

void pushToStack(char element) {

    if(isStackFull()){
        cout<<"Stack is full";
        return;
    }
    else{
        stackArray[stackTop+1] = element;
        stackTop++;
    }
    
}

char popFromStack() {

    if(isStackEmpty()){
        cout<<"Stack is empty";
        return '-1';
    }
    else{
        return stackArray[stackTop--];
    }
    
}

int main() {
    string inputString = "Hello, World!";
    int inputLength = inputString.length();


    for (int i = 0; i < inputLength; i++) {
        char currentChar = inputString[i];
        pushToStack(currentChar);
    }


    string reversedString;
    while (!isStackEmpty()) {
        reversedString.push_back(popFromStack());
    }
    cout << reversedString << "\n";
    return 0;
}