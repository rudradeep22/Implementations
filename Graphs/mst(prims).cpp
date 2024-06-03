//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> key(V, INT_MAX); // Key values used to pick minimum weight edge in cut
        vector<bool> inMST(V, false); // To represent set of vertices included in MST
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap to get the edge with minimum weight

        key[0] = 0;
        pq.push({0, 0}); 

        int res = 0; 

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue; 

            inMST[u] = true;
            res += key[u]; 

            for (auto &edge : adj[u]) {
                int v = edge[0];
                int weight = edge[1];
                if (!inMST[v] && key[v] > weight) {
                    key[v] = weight;
                    pq.push({key[v], v}); 
                }
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