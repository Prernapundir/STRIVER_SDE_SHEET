/*
https://www.codingninjas.com/codestudio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0

*/

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
private:
    Node* root;
public:
    Trie() {
      root=new Node();
    }

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

    bool checkAllPrefixExists(string &word){
        Node *node=root;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                if(node->isEnd()==false) return false;
            }else return false;
        }
        return true;
    }
    
    Node* getTrieNode(){
        return root;
    }
};

string completeString(int n, vector<string> &a){
    Trie* trie=new Trie();
    
    for(auto s:a){
        trie->insert(s);
    }
    string ans="";
    
    for(auto it:a){
        if(trie->checkAllPrefixExists(it)){
            if(it.length()>ans.length()) ans=it;
            else if(ans.length()==it.length() and it<ans){
                ans=it;
            }
        }
    }
    return ans!=""?ans:"None";
}
