//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int, pair<int, int>> ppi;
class DisjointSet{
  vector<int> size, parent;
  public:
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int findpar(int node){
        if(node == parent[node]){
            return node;
        }
        parent[node] = findpar(parent[node]);
        return parent[node];
    }
    void unionBySize(int u, int v){
        int pu = findpar(u);
        int pv = findpar(v);
        if(pu == pv) return;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
       vector<ppi> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int u = i;
                int v = it[0];
                int w = it[1];
                if (u < v) {
                    edges.push_back({w, {u, v}});
                }
            }
        }
        sort(edges.begin(), edges.end());
        int res = 0;
        DisjointSet ds(V);
        for(auto edge : edges){
            int u = edge.second.first, v = edge.second.second, w = edge.first;
            int pu = ds.findpar(u);
            int pv = ds.findpar(v);
            if(pu != pv){
                res += w;
                ds.unionBySize(u, v);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends