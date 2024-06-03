#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;
int t[2 * MAX_N]; 

void build(int a[], int n) {
    for (int i = 0; i < n; i++) {
        t[n + i] = a[i];
    }
    for (int i = n - 1; i > 0; --i) {
        t[i] = t[i * 2] + t[i * 2 + 1];
    }
}

void update(int pos, int val, int n) {
    pos += n;
    t[pos] = val;
    for (int i = pos / 2; i > 0; i /= 2) {
        t[i] = t[i * 2] + t[i * 2 + 1];
    }
}

int query(int l, int r, int n) {
    l += n; 
    r += n;
    int sum = 0;
    while (l <= r) {
        if (l % 2 == 1) {
            sum += t[l];
            l++;
        }
        if (r % 2 == 0) {
            sum += t[r];
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return sum;
}

int main() {
    int n = 10;
    int a[10] = {10, 23, 43, 12, 56, 67, 11, 89, 27, 82};
    build(a, n);
    cout << query(2, 5, n) << endl; // Query the sum in range [2, 5]
    update(4, 88, n); // Update the value at position 4 to 88
    cout << query(2, 5, n) << endl; // Query the sum in range [2, 5] again
    cout << "Done!" << endl;
    return 0;
}
