
#include<bits/stdc++.h>

class Node{
    public:
    vector<Node*> links;
    bool flag;
    Node(){
        vector<Node*> temp(26);
        links=temp;
        flag=false;
    }
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void put(Node* node,char ch){
        links[ch-'a']=node;
        return;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag=true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie {

public:
    Node* root;
    /** Initialize your data structure here. */
    Trie() {
      root=new Node();
     }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(new Node(),word[i]);
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node=root;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }else return false;
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *node=root;
        for(int i=0;i<prefix.length();i++){
            if(node->containsKey(prefix[i])){
                node=node->get(prefix[i]);
            }else return false;
        }
        return true;
    }
};
