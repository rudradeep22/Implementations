//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs_st(int x, stack<int> &st, vector<vector<int>> &adj, vector<int> &vis){
	    vis[x] = 1;
	    for(auto ver : adj[x]){
	        if(vis[ver] == 0)
	            dfs_st(ver, st, adj, vis);
	    }
	    st.push(x);
	}
	vector<int> find_order(int V, vector<vector<int>> &adj){
	    vector<int> order;
	    stack<int> st;
	    vector<int> vis(V, 0);
	    for(int i=0; i<V; i++){
	        if(vis[i] == 0)
	            dfs_st(i, st, adj, vis);
	    }
	    while(!st.empty()){
	        order.push_back(st.top());
	        st.pop();
	    }
	    return order;
	}
	
	void dfs(int x, vector<vector<int>> &adj_new, vector<int> &vis){
	    vis[x] = 1;
	    for(auto ver : adj_new[x]){
	        if(vis[ver] == 0)
	            dfs(ver, adj_new, vis);
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> order = find_order(V, adj);
        vector<vector<int>> adj_new(V);
        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++){
                adj_new[adj[i][j]].push_back(i);
            }
        }
        vector<int> vis(V, 0);
        int count = 0;
        for(auto i : order){
            if(vis[i] == 0){
                dfs(i, adj_new, vis);
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends