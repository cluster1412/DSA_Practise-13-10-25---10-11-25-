#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isEnd;

    TrieNode(char ch){
        data = ch;
        for(int i = 0 ; i < 26; i++){
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root, string s){
        if(s.size() == 0){
            root->isEnd = true;
            return;
        }
        int index = s[0] - 'a';
        TrieNode* child;
        if(root->children[index] == nullptr){
            child = new TrieNode(s[0]);
            root->children[index] = child;
        }
        else{
            child = root->children[index];
        }
        insertUtil(child,s.substr(1));
    }
    void insert(string word) {
        insertUtil(root,word);
    }
    bool searchUtil(TrieNode* root,string s){
        if(s.size()==0){
            return root->isEnd;
        }
        int index = s[0] - 'a';
        if(root->children[index] != nullptr){
             return searchUtil(root->children[index],s.substr(1));
        }
        return false;
    }
    bool search(string word) {
        return searchUtil(root,word);
    }
    
    bool prefixUtil(TrieNode* root,string s){
        if(s.size()==0){
            return true;
        }
        int index = s[0] - 'a';
        if(root->children[index] != nullptr){
             return prefixUtil(root->children[index],s.substr(1));
        }
        return false;
    }

    bool startsWith(string prefix) {
        return prefixUtil(root,prefix);
    }
};
