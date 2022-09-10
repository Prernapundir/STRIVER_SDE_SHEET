/*
Approach

BFS+DFS Approach
-----------------

One of best problem so far
Steps :
1. Use BFS to find the shortest distance sequence and build the parent -> child relationship graph in (reverse order)
2. Use DFS to find print the paths


Why we used BFS ?
-------------------
Becoz BFS gives us shortest path from source to distance, becoz it trverse level wise
DFS trverse in depth order manner , it will be time consuming to find the shortest path and leads to TLE

What is parent->child graph ?
-----------------------------
1. To avoid the TLE , we have to make parent->child graph so that DFS won't take much time to print the paths
2. Becoz there is no point to traverse back and within same level
3. So we have to make a parent->child graph using visited_map which will store the level and visited node


why to build parent->child graph in reverse order ?
-------------------------------------------------
1. Becoz if we will start from source to end , we can encounter dead ends , so we have to build graph
beginWord  <--- endWord, becoz from child to parent path will always exists


*/

class Solution {
public:
    vector<vector<string>> ans;
    
  // dfs to print the paths
    void dfs(unordered_map<string,vector<string>>&adj,string &beginWord,string &endWord,vector<string>&temp){
        temp.push_back(beginWord);
        
        if(beginWord==endWord){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        for(auto neigh:adj[beginWord]){
            dfs(adj,neigh,endWord,temp);
        }
        temp.pop_back();
        return;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> visited;
        set<string> st(wordList.begin(),wordList.end());
        
        q.push(beginWord);
        visited[beginWord]=0;
        
        
        while(!q.empty()){
            int size=q.size();
            
            while(size--){
                string front=q.front();
                q.pop();
                
                for(int i=0;i<front.length();i++){
                    string temp=front;
                    for(char ch='a';ch<='z';ch++){
                        temp[i]=ch;
                        
                        if(temp==front) continue;
                        else if(st.find(temp)!=st.end()){     // check whether the temp word is in set:wordlist
                            if(visited.find(temp)!=visited.end()){  // check if word is visited
                                if(visited[temp]>visited[front]){   // if word is visited , check its level , same or less we won't care , only above level we have to consider
                                    adj[temp].push_back(front);  // building the graph in reverse order
                                }
                            }else{
                                q.push(temp);  // add to queue
                                visited[temp]=visited[front]+1;  // if not visited , make it visited 
                                adj[temp].push_back(front);    // add to graph in revrse order
                            }
                        }
                    }
                }
            }
        }
        
       
        
        
        vector<string> temp;
        dfs(adj,endWord,beginWord,temp);
        
        for(int i=0;i<ans.size();i++){
            reverse(ans[i].begin(),ans[i].end()); // becoz we traversed the graph in reverse order , now path needs to be reversed
        }
        
        return ans;
    }
};
