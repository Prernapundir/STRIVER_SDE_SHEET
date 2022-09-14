

/*
Learning

Dijkstra algorithm 
----------------------

Along with Dijastra , we have to make a dp array and take care when the weight of visited node becomes equal again the weight of newWeight , means we have more ways to reach this node.


Leetcode link :
https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

*/

#define ll long long
#define pll pair<ll, ll>

class Solution {
public:
    int mod=1e9+7;
    
    int countPaths(int n, vector<vector<int>>& roads) {
        
    vector<pair<int,int>> adj[n];
    
    for(auto x:roads){
        adj[x[0]].push_back({x[1],x[2]});
        adj[x[1]].push_back({x[0],x[2]});
    }
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vector<ll> dist(n,LONG_MAX);
        
    vector<ll> dp(n,0);
    
    pq.push({0,0});
    dist[0]=0;
    dp[0]=1;
    
    while(!pq.empty()){
        auto front=pq.top();
        pq.pop();
        
        ll node=front.second;
        ll weight=front.first;
        
        for(auto neigh:adj[node]){
            ll newWeight=neigh.second;
            ll newNode=neigh.first;
            
            if(dist[newNode]>dist[node]+newWeight){  // if node visited first time , or have max distnce from source 
                dist[newNode]=dist[node]+newWeight;
                pq.push({dist[newNode],newNode});
                dp[newNode]=dp[node]%mod;
            }
            else if(dist[newNode]==weight+newWeight){   // node is visited and have equal weight means we can reach here in many ways
                 dp[newNode]=(dp[newNode]%mod+dp[node]%mod)%mod;   // so just maintain a dp array for the no of ways 
            }
        }
      }
        
    return dp[n-1];
    }
};
