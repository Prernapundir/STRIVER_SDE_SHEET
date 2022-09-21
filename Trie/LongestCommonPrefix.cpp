/*

Trie implementaation, 
Firtly insert all strings in trie
then iterate over trie and check till what node we have single element in trie and then keep appending that to your answer

https://leetcode.com/problems/longest-common-prefix/

*/


class Node{
    public:
    vector<Node*> links;
    bool end;
    
    Node(){
        vector<Node*> temp(26);
        links=temp;
        end=false;
    }
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        end=true;
    }
    
    int countNodeChilds(int &index){
        int count=0;
        for(int i=0;i<26;i++){
            if(links[i]!=NULL){
                count++;
                index=i;
            }
        }
        return count;
    }
    
    bool isEnd(){
        return end;
    }
};

class Trie{
    private:
    Node* root;
    
    public:
    
    Trie(){
        root=new Node();
    }
    
    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
        return;
    }
    
    Node* getTrieNode(){
        return root;
    }
};

class Solution {
public:
   
    
    string longestCommonPrefix(vector<string>& strs) {
        Trie* trie=new Trie();
        
        for(auto s:strs){
            trie->insert(s);
        }
        
        Node* node=trie->getTrieNode();
        
        string ans;
        int index=-1;
        while(node and !node->isEnd() and node->countNodeChilds(index)==1){
            ans+='a'+index;
            node=node->get('a'+index);
        }
        
        return ans;
        
    }
};
