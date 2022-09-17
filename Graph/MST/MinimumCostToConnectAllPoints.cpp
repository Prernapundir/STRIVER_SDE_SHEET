/*

Learning :
Normal Prims Algo 


*/

#define ppl pair<int,int>

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        
        priority_queue<ppl,vector<ppl>,greater<ppl>> pq;
        pq.push({0,0});
        
        vector<int> dist(n,INT_MAX); // distance array
        vector<bool> inMST(n); // mST array
        
        int ans=0;
        dist[0]=0;
        
        while(!pq.empty()){
            auto f=pq.top();
            pq.pop();
            
            if(inMST[f.second]) continue;
            
            auto node=points[f.second];
            inMST[f.second]=true;
            
            
            for(int i=0;i<n;i++){
                auto currNode=points[i];
                
                if(!inMST[i]){
                    int distance=abs(node[0]-currNode[0]) + abs(node[1]-currNode[1]);
                    if(dist[i]>distance){
                        pq.push({distance,i});
                        dist[i]=distance;
                    }
                }
            }
            
        }
        
        for(auto x:dist) ans+=x;
        return ans;
        
    }
};
