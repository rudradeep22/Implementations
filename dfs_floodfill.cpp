// Flood Fill algorithm

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, int i, int j, int newColor, int initialColor){
    int n = graph.size();
    int m = graph[0].size();
    if(i < 0 || j < 0 || i >= n || j >= m) 
        return;
    if(graph[i][j] != initialColor) 
        return;
    
    graph[i][j] = newColor;

    dfs(graph, i-1, j, newColor, initialColor);
    dfs(graph, i+1, j, newColor, initialColor);
    dfs(graph, i, j-1, newColor, initialColor);
    dfs(graph, i, j+1, newColor, initialColor);
}   

int main(){
    vector<vector<int>> graph = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1;
    int sc = 1;
    dfs(graph, sr, sc, 2, 1);

    for(auto el : graph){
        for(auto ele : el)
            cout << ele << " ";
        cout << endl;
    }
    return 0;
}