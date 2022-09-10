/*
DFS -> visit the nodes in depth manner

Complexities : Similar to BFS

*/



void dfs(vector<int>adj[],int src,vector<bool>&vis,vector<int>&temp){
	vis[src]=true;
    temp.push_back(src);
    
    for(auto neigh:adj[src]){
        if(!vis[neigh]){
            dfs(adj,neigh,vis,temp);
        }
    }
    return;
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
	vector<int> adj[V+1];
	vector<vector<int>> ans;
	vector<bool> vis(V+1);
	
	for(int i=0;i<edges.size();i++){
		adj[edges[i][0]].push_back(edges[i][1]);
		adj[edges[i][1]].push_back(edges[i][0]);
	}
	
	for(int i=0;i<V;i++){
		if(!vis[i]){
			vector<int> temp;
			dfs(adj,i,vis,temp);
			ans.push_back(temp);
		}
	}
	
	return ans;
}
