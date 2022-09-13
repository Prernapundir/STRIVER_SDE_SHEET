#include <bits/stdc++.h>

// DFS function
bool DFS(vector<int>adj[],vector<bool>&vis,int src,int parent){
    vis[src]=true;
    
    for(auto x:adj[src]){
        if(!vis[x]){
            if(helper(adj,vis,x,src))
            return true;
        }else if(x!=parent){
            return true;
        }
    }
    return false;
}


//main function
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    vector<bool> vis(n+1);
    
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(DFS(adj,vis,i,-1)) return "Yes";
        }
    }
    return "No";
}
