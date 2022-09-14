class Solution {
public:
    
    bool bfs(int src,vector<int>&color,vector<vector<int>>& graph){
        queue<int> q;
        q.push(src);
        color[src]=1;
        
        while(!q.empty()){
            int f=q.front();
            q.pop();
            
            for(auto x:graph[f]){
                if(!color[x]){
                    q.push(x);
                    color[x]=-color[f];
                }else if(color[x]==color[f]) return false;
            }
        }
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        
        for(int i=0;i<n;i++){
            if(!color[i] ){
               if(!bfs(i,color,graph)) return false;
            }
        }
        
        return true;
    }
};
