

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfsTopo(int src,vector<bool>&vis,stack<int>&st,vector<int>adj[]){
	    vis[src]=1;
	    for(auto x:adj[src]){
	        if(!vis[x]){
	          dfsTopo(x,vis,st,adj);
	        }
	    }
	    st.push(src); // push into the stack while coming back from recursive call
	    return;
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool>vis(V);
	    vector<int>ans;
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfsTopo(i,vis,st,adj);
	        }
	    }
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
