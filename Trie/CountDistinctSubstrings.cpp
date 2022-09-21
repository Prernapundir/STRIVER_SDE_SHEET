/*

https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292?leftPanelTab=0

*/


class Node{
    public:
    vector<Node*> links;
    Node(){
        vector<Node*> temp(26);
        links=temp;
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
};

class Trie {
private:
    Node* root;
public:
    Trie() {
      root=new Node();
    }

    // while insert keep count for distinct substrings
    int insert(string word) {
        int count=0;
        Node *node=root;
        
        for(int i=0;i<word.length();i++){
            node=root;
            for(int j=i;j<word.length();j++){
                if(!node->containsKey(word[j])){
                    count++;
                    node->put(new Node(),word[j]);
                }
                node=node->get(word[j]);
            }
            
        }
        return count+1;
    }

    Node* getTrieNode(){
        return root;
    }
    
};

int countDistinctSubstrings(string &s)
{
    Trie* trie=new Trie();
    return trie->insert(s);
    
}
