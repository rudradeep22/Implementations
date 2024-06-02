#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;
int t[4 * MAX_N]; // need to store at most 4n vertices

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl]; // range is [tl, tl]
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);        // range : [tl, tm]
        build(a, v * 2 + 1, tm + 1, tr); // range : [tm+1, tr]
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int query(int v, int tl, int tr, int l, int r) { // query : sum of [l, r]
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) +
           query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int val) { // val to be updated at pos
    if (tl == tr)
        t[v] = val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main() {
    int n = 10;
    int a[10] = {10, 23, 43, 12, 56, 67, 11, 89, 27, 82};
    // tree starts from pos 1
    build(a, 1, 0, n - 1);
    cout << query(1, 0, n - 1, 2, 5) << endl;
    update(1, 0, n - 1, 4, 88);
    cout << query(1, 0, n - 1, 2, 5) << endl;
    cout << "Done!" << endl;
    return 0;
}
/*
Above is a quick and dirty implementation of a segment tree where nodes are
numbered in BFS(level order traversal). If numbered in pre order traversal, we could
have saved memory upto 2n
*/
