
/*
	Notes:
	1- No self loop or parelled edges 
	2- We try to connect all the nodes 
	3- We start by picking 1 node 
	4- Then we select the smallest edge from this node 
	5- Now we have 2 nodes
	6- Now we select the min edge from these 2 nodes
	7- This way we keep including nodes and covers up all nodes
	8- In total we have V nodes and V-1 edges
	9- We use adj list 
	Time Complexity :- O((V+E)Log(V))
	Space Complexity :- O(E+V)
*/


void prims(vector<pair<int,int>> adj[],int n,vector<bool> &mst,vector<int> &parent,vector<int> &key){
    
    // creating min-heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    key[1]=0;
    
    while(!pq.empty()){
        auto f=pq.top().second;
        pq.pop();
        
        if(mst[f]) continue;
        mst[f]=true;

        for(auto neigh:adj[f]){
            int node=neigh.second;
            int weight=neigh.first;
            
            if(!mst[node] and key[node]>weight){ // if not in mst ,weight of (f,neigh) is smaller than current key of neigh
                key[node]=weight;
                pq.push({key[node],node});
                parent[node]=f;
            }
        }
    }
    return;
}

void main(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int,int>> adj[n+1];
    
    for(auto x:g){
        adj[x.first.first].push_back({x.second,x.first.second});
    }
    
    vector<bool> mst(n+1); // visited array
    vector<int> parent(n+1,-1); // to store parent
    vector<int> key(n+1,INT_MAX); // to store keys 
    
    prims(adj,n,mst,parent,key);

    //print edges from u->v
      for (int i = 1; i < V; ++i)
        cout<<parent[i]<<i;
      }
}
