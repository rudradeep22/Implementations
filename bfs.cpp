#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int v1, int v2){
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}

vector<int> bfs(vector<int> adj[], int V){
    bool vis[V] = {false};
    vis[0] = true;
    queue<int> q;
    vector<int> ans;
    q.push(0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto nb : adj[node]){
            if(!vis[nb]){
                vis[nb] = true;
                q.push(nb);
            }
        }
    }
    return ans;
}

int main(){
    vector<int> adj[500];
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        addEdge(adj, v1, v2);
    }
    
    vector<int> ans = bfs(adj, n);

    for(auto el : ans){
        cout << el << " ";
    }
    cout << endl;
    return 0;
}