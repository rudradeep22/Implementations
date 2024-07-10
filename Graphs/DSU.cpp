#include <bits/stdc++.h>
using namespace std;

/*
For questions on dynamic graphs tht have intermediate queries
*/
class DisjointSet{
private:
    vector<int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++){ // if 1 based indexing
            parent[i] = i;
        }
    }
    int findUpar(int node){ // find ultimate parent
        if(node == parent[node]){
            return node;
        }
        parent[node] = findUpar(parent[node]); // path compression for O(1)
        return parent[node];
    }
    void unionByRank(int u, int v){
        int pu = findUpar(u);
        int pv = findUpar(v);
        if(pu == pv) return ;
        if(rank[pu] < rank[pv]) {
            parent[pu] = pv; // pu gets attached to pv
        }
        else if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu;
            rank[pu]++; // u increases by 1 size 
        }

    }
    void unionBySize(int u, int v){
        int pu = findUpar(u);
        int pv = findUpar(v);
        if(pu == pv) return ;
        if(size[pu] < size[pv]) {
            parent[pu] = pv; // pu gets attached to pv
            size[v] += size[u];
        }
        else {
            parent[pv] = pu;
            size[u] += size[v];
        }
    }
};

int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUpar(3) == ds.findUpar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUpar(3) == ds.findUpar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}