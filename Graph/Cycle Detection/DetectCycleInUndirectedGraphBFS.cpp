/*Learning

1. Check if currNode is already visited , then parent[src]==currNode  => If No , then cycle present
becoz , if node is already visted , means someone either someone else visited that node , or it's parent node of currNode

*/


#include <bits/stdc++.h>

bool helper(vector<int>adj[],vector<bool>&vis,int src,vector<int>&parent){
    queue<int> q;
    q.push(src);
    vis[src]=true;
    
    while(!q.empty()){
        int front=q.front();
        q.pop();
        
        for(auto neigh:adj[front]){
            if(!vis[neigh]){
                parent[neigh]=front;
                q.push(neigh);
                vis[front]=true;
            }else if(parent[front]!=neigh){
                return true;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    vector<bool> vis(n+1);
    
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    vector<int> parent(n+1,-1);
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(helper(adj,vis,i,parent)) return "Yes";
        }
    }
    return "No";
}
