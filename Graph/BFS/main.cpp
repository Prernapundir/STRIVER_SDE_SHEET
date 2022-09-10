
/*
Approach

1. BFS -> Traversal technique
2. Visit adjacent nodes first
3. Used queue data structure [FIFO ]

Time complexity : O(N+E) , N=no of nodes , E= no of adjacent nodes
Space complexity : O(N+E) -> For adjacency list , O(N) -> for queue , O(N) -> for visited array

*/

#include<bits/stdc++.h>
using namespace std;

void bfs(int src,vector<int> adj[],vector<int>&ans,vector<bool>&vis){
    queue<int> q;
    q.push(src);
    vis[src]=true;
    
  //bfs logic 
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        
        for(auto neigh:adj[front]){
            if(!vis[neigh]){
                q.push(neigh);
                vis[neigh]=true;
            }
        }
    }
    
    return;
}


vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> adj[vertex];
    vector<int> ans;
    
  //making adjacency list
    for(auto x: edges){
        adj[x.first].push_back(x.second);
        adj[x.second].push_back(x.first);
    }
    
    vector<bool> vis(vertex+1,0);
    
  // becuase we have to print in sorted order
    for(int i=0;i<vertex;i++){
        sort(adj[i].begin(),adj[i].end());
    }
  
  // looping to handle disconnected graph case as well
    for(int i=0;i<vertex;i++){
        if(!vis[i]){
            bfs(i,adj,ans,vis);
        }
    }
    
    return ans;
}
