/*
	TC O(V+E)*logV
	PC O(V)
  
	Implementations wise its like BFS ( instead of queue we use priority queue)
	0-Is there are negetive edges but not in a cycle then we an use this algo
	1-If there are negetive edges in a cycle we cant use this also 
	2-for this we use bellman ford
	3-It there are negetive weight cycles then we cant use bellman ford too, we 
	can just detect negetive weight cycles using bellman ford
*/

// https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<pair<int,int>> adj[vertices+1];
    
    for(auto x:vec){
        adj[x[0]].push_back({x[1],x[2]});
        adj[x[1]].push_back({x[0],x[2]});
    }
    
    vector<int> ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(vertices,INT_MAX);
    
    pq.push({0,source});
    dist[source]=0;
    
    while(!pq.empty()){
        auto front=pq.top();
        pq.pop();
        
        int node=front.second;
        int weight=front.first;
        
        for(auto neigh:adj[node]){
            int newWeight=dist[node]+neigh.second;
            int newNode=neigh.first;
            
            if(dist[newNode]>newWeight){
                dist[newNode]=newWeight;
                pq.push({newWeight,newNode});
            }
        }
    }
    
    for(auto x:dist){
        ans.push_back(x);
    }
    return ans;
}
