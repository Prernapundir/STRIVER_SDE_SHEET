// Notes

/*
    Notes
    1-We can easily solve the problem of IsBipartite graph by DFS/BFS alternate colouring
    2-Property to be Bipartite ( either no cyle ie Tree. OR even len cycles ) 
    3-Odd len cycles simply means not bipartite
    4-We can use this colouring technique to find if there is odd len cycle ( just check if graph is not Bipartite)
    
*/

class Solution {
public:
    
    bool dfs(int src,vector<vector<int>>& graph,vector<int>&color,vector<bool>&vis,int parent){
        vis[src]=true;
        color[src]=-parent;
        
        for(auto neigh:graph[src]){
            if(!vis[neigh]){
                if(!dfs(neigh,graph,color,vis,-parent)) return false;
            }else if(color[neigh]==color[src]) return false;
        }
        
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
     
        vector<int> color(n,0);
        vector<bool> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!dfs(i,graph,color,vis,1)) return false;
            }
        }
        
        return true;
    }
};
