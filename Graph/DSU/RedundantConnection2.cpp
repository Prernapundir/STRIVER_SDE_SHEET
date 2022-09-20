/*

Three case arise when whn we try to add one extra edge in tree

1. Node with 2 parents only
2. Cycle exists only
3. Cycle exits +2 parents (both)

*/


class Solution {
public:
    
  // DSU find function
    int find(int node,vector<int>&parent){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=find(parent[node],parent);
    }
    
  //DSU union function
    bool Union(int u,int v,vector<int> &parent,vector<int>&rank){
        u=find(u,parent);
        v=find(v,parent);
        
        if(u==v) return true;
        
        if(rank[u]>rank[v]){
            parent[v]=u;
        }else if(rank[v]>rank[u]){
            parent[u]=v;
        }else{
            parent[u]=v;
            rank[v]++;
        }
        return false;
    }
    
  // find the cycle with skipNode method as like we did in Redundant Connection 1
    vector<int> findCycle(vector<vector<int>>& edges,int n,vector<int>skipNode){
        vector<int> parent(n),rank(n,0);
        
        for(int i=0;i<n;i++) parent[i]=i;
        
        for(auto x:edges){
            if(x==skipNode) continue;
            if(Union(x[0],x[1],parent,rank)) return x;
        }
        return {};
    }
    
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int> indegree(n,0);
        
        int node_with_2_indegree=-1; // node with 2 parents
        
        for(auto x:edges){
            indegree[x[1]]++;
            if(indegree[x[1]]==2){
                node_with_2_indegree=x[1]; 
            }
        }
        
        if(node_with_2_indegree==-1){
            // no node with 2 parents , means cycle present so just detect the cycle using dsu method
            return findCycle(edges,n,{});
        }else{
            // node with 2 parents, it can have cycle or not
            for(int i=n-2;i>=0;i--){
                if(edges[i][1]==node_with_2_indegree){// start from last of edges array , becoz we have to give the last edge(order wise of input) as mentioned
                    auto res=findCycle(edges,n,edges[i]); // lets suppose edge[i]=skipNode(we will skip this node , and will try to build the graph)
                    if(res.size()==0) return edges[i]; //( if we are able to build the graph without this node , means no cycle exits , so this edges is our answer)
                }
            }
        }
        
        return {};
    }
};
