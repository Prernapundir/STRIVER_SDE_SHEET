/*Learnings

1. Similar to Dijastra with minor change,
2.here we have to make the distance array of stops and no need to travsres the node who have fever stops
3.if we will make the distnace array of weights , that will be incorrect, becoz smaller distance path can have more than k stops
and largere distance path can have less than k stops 
4. So push all the nodes in the queue, irrescptive of weight, on stops we can have optimization


https://leetcode.com/problems/cheapest-flights-within-k-stops/
*/


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        
        for(auto f:flights) adj[f[0]].push_back({f[1],f[2]});
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({0,src,0}); //{price,src,stops}
        
        int ans=INT_MAX;
        vector<int> dist(n,INT_MAX);// distnace array to store the stops
        
        while(!pq.empty()){
            auto [price,node,stops]=pq.top();
            pq.pop();
            
            //if we found the node==destination,return the first encounter node, becuas edijastra greedily picks the node with fever k steps
            if(node==dst) {
                return price;
            }
            
            // for the optimization
            if(stops>k or dist[node]<stops) continue;
            dist[node]=stops;
            
            for(auto neigh:adj[node]){
                pq.push({price+neigh.second,neigh.first,stops+1});
            }
        }
        
        return -1;
    }
};
