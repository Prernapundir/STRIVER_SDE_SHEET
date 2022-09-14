/*
Learnings

Approach 1: 
-----------------
Couse schedule , if we look carefully , it saying us to detect a cycle in directed graph
If cycle present => not able to finish the course

So , Use dfs to detect the cycle 

Approach 2:
---------------
Use topological sort

*/

class Solution {
public:
    
    bool dfs(vector<bool>&vis,vector<bool>&dfsVis,int src,vector<int> adj[]){
        vis[src]=true;
        dfsVis[src]=true;
        
        for(auto neigh:adj[src]){
            if(!vis[neigh]){
                if(dfs(vis,dfsVis,neigh,adj)) return true;
            }else if(dfsVis[neigh]) return true;
        }
        
        dfsVis[src]=false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses+1];
        
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        
        vector<bool> vis(numCourses+1),dfsVis(numCourses+1);
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(vis,dfsVis,i,adj)) return false;
            }
        }
        
        return true;
          
    }
};
