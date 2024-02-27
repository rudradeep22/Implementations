// Connected Components
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];

void dfs(int vertex){
    if(vis[vertex])
        return;
    
    vis[vertex] = true;
    for(auto child : g[vertex]){
        dfs(child);
    }
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
    int c = 0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);
            c++;
        }
    }
    cout << c << endl;
    return 0;
}