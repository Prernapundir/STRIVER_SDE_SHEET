/*

Learning

1. Just a topological sort ,
2. Just need to have one dp array for every node for storing color value i path reach to this node


*/

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n=colors.size();
        vector<int> adj[n],indegree(n);
        
        vector<vector<int>>dp(n,vector<int>(26));   // dp[node][color]
        queue<int> q;
        int ans=-1;
        int totalNodesVisited=0;  // to detect cycle
        
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            totalNodesVisited++;
            int currColorValue=colors[front]-'a';  // increment current node color value
            dp[front][currColorValue]++;
            
            ans=max(ans,dp[front][currColorValue]);
            
            for(auto neigh:adj[front]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
                
                for(int i=0;i<26;i++){
                    dp[neigh][i]=max(dp[neigh][i],dp[front][i]);  // store color array as per parent node array
                }
            }
        }
        
        return totalNodesVisited==n?ans:-1;
    }
};
