class Node{
    private:
    vector<Node*> links;
    string word;
    bool flag;
    
    public:
    Node(){
        vector<Node*> temp(26);
        links=temp;
        flag=false;
        word="";
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
    
    bool isEnd(){
        return flag;
    }
    
    void setEnd(bool flag){
        this->flag=flag;
    }
    
    void setWord(string &s){
        word=s;
    }
    
    string getWord(){
        return word;
    }
};

class Trie {
public:
    Node* root;
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
        
        node->setWord(word);
        node->setEnd(true);
    }
    
    Node* getTrieNode(){
        return root;
    }

};

class Solution {
public:
    
    vector<string> ans;
        
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    
    bool isSafe(int m,int n,int x,int y){
        return x>=0 and y>=0 and x<m and y<n;
    }
    
    void dfs(vector<vector<char>>& board,Node* node,int m,int n,int x,int y){

        if(!isSafe(m,n,x,y) or board[x][y]=='$' ) return ;
        
        char ch=board[x][y];
       
        node=node->get(ch);

        if(node==NULL) return;
        
        if(node->isEnd()){
            ans.push_back(node->getWord());
            node->setEnd(false);
        }
        
        board[x][y]='$';
        
        for(int i=0;i<4;i++){

            int nx=dx[i]+x;
            int ny=dy[i]+y;
            
            if(isSafe(m,n,nx,ny)){
                dfs(board,node,m,n,nx,ny);
            }
        }
        
        board[x][y]=ch;
        return ;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m=board.size();
        int n=board[0].size();
        
        Trie* trie=new Trie();
        
        for(auto w:words){
            trie->insert(w);
        }
        
        Node* temp=trie->getTrieNode();
        Node* node=temp;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                node=temp;
                dfs(board,node,m,n,i,j);
            }
        }
        
        return ans;
    }
};
