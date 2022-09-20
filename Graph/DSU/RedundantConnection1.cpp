/*
Approach :

Normal DSU implementation , to remove the redundant edge, keep buildiog the graph, when u found parent[u]==parent[v means thts the edge u have to remove

*/

class Solution {
public:
    int find(int node ,vector<int> &parent){
        if(parent[node]==node) return node;
        return parent[node]=find(parent[node],parent);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1),rank(n+1,0);
        
        for(int i=0;i<n;i++) parent[i]=i;
        
        for(auto e:edges){
            int u=find(e[0],parent);
            int v=find(e[1],parent);
            
            if(u==v) return e;
            
            if(rank[u]>rank[v]){
                parent[v]=u;
            }else if(parent[v]>parent[u]){
                parent[u]=v;
            }else{
                parent[v]=u;
                rank[u]++;
            }
        }
        
        return {};
    }
};
