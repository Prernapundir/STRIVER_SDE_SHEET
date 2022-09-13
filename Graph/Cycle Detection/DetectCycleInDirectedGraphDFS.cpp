/*

1. Cycle will present if we will visit the same node again in the path
2. We have to take a stack {dfsVis } to keep track for the elements in stack so far

*/

#include<bits/stdc++.h>

bool dfs(int src,vector<int> adj[],vector<bool> &vis,vector<bool> &dfsVis){
    dfsVis[src]=true;
    vis[src]=true;
    
    for(auto neigh:adj[src]){
        if(!vis[neigh]){
            if(dfs(neigh,adj,vis,dfsVis)) return true;
        }else if(dfsVis[neigh]){
            return true;
        }
    }
    dfsVis[src]=false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  
    vector<int> adj[n+1];
    
    for(int i=0;i<edges.size();i++){
        adj[edges[i].first].push_back(edges[i].second);
    }
    
    vector<bool> vis(n+1),dfsVis(n+1);
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,dfsVis)) return 1;
        }
    }
    
    return 0;
}
