// Example of DFS in trees
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int depth[N], height[N]={0};

void dfs(int vertex, int parent = 0){

    for(auto child : g[vertex]){
        if(child == parent)
            continue;
        depth[child] = depth[parent] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child]+1);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);

    for(int i=1; i<=n; i++){
        cout << depth[i] << " " << height[i] << endl;
    }
    return 0;
}