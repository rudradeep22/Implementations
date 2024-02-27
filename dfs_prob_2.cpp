// Cycle Detection
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];

bool dfs(int vertex, int parent){
    if(vis[vertex])
        return false;

    vis[vertex] = true;
    for(auto child : g[vertex]){
        if(child == parent)
            continue;
        if (!dfs(child, vertex)){
            return false;
        }
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bool isNotCycle = true;
    for(int i=1; i<=n; i++){
        if(!vis[i])
            if(!dfs(i, 0))
                isNotCycle = false;
    }
    cout << !isNotCycle << endl;
    return 0;
}