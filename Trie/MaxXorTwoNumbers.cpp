/*
Approach:

1. Store every number in trie as a binary form
2. For the maximum xor , 
let x=101 and x^y would be max if we would n=be able to get y=010 , oppsite values in both x and y would give max xor
so , after inserting all numbers in trie in binary form , lets start picking the number(x) of arry again and keep checking in trie for max xor
3. So for x , we ahve to search y which can build the maximum xor value .

*/


class Node{
    public:
    vector<Node*> links;
    Node(){
        vector<Node*> temp(2,NULL);
        links=temp;
    }
    
    Node* get(int bit){
        return links[bit];
    }
    
    void put(int bit,Node* node){
        links[bit]=node;
    }
    
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    
};

class Trie{
    private:
    Node* root;

    public:
    
    Trie(){
        root=new Node();
    }
    
    void insert(int num){
        Node* node=root;
        
        // as every number is 32 bit , so start inserting the number bit from MSB
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1; // take msb bit 
            if(!node->containsKey(bit)){  // if its not in the tree , then isert
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    
    // to get maximum xor value
    int getMaxXor(int num){
        Node* node=root;
        int ans=0;
        
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1; // take msb bit 
            if(node->containsKey(1-bit)){ // if bit =0 , check for 1 and vice versa in the tree
                ans=ans| (1<<i); // if we found oppsite bit , then take a or with this (1<<i: it will give the 1 at that position) becase we can make 1 now
                node=node->get(1-bit); // only different bits can make 1 
            }else node=node->get(bit);  // else no option keep continue, becuase this bit won't make any difference 
        }
        
        return ans;
    }
    
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie=new Trie();
        
        //insert first one by one
        for(auto n:nums){
            trie->insert(n);
        }
        
        int ans=0;
        // search one by one now
        for(auto n:nums){
            int val=trie->getMaxXor(n);
            ans=max(ans,val);
        }
        
        return ans;
    }
};
