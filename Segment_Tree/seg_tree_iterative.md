## Iterative Segment Tree Implementation

### Introduction

A segment tree is a data structure used for storing information about intervals or segments. It allows querying and updating the array efficiently. The iterative version avoids the overhead of recursive calls and can be more efficient for large arrays.

### Components of the Implementation

1. **Tree Array (`t`)**: Stores the segment tree.
2. **Build Function**: Constructs the segment tree from the input array.
3. **Update Function**: Updates the value at a specific position and propagates the changes up the tree.
4. **Query Function**: Calculates the sum of elements in a given range.

### Detailed Working

#### 1. Building the Tree

- **Initialization**: Leaves are initialized with the values of the input array.
- **Building**: Internal nodes are calculated as the sum of their children nodes.

```cpp
void build(int a[], int n) {
    // Initialize leaves
    for (int i = 0; i < n; i++) {
        t[n + i] = a[i];
    }
    // Build the tree by calculating parents
    for (int i = n - 1; i > 0; --i) {
        t[i] = t[i * 2] + t[i * 2 + 1];
    }
}
```

- **Example**: For an array `a` of size 10:
  - Leaves: Stored at `t[10]` to `t[19]`.
  - Internal nodes: Calculated bottom-up starting from `t[9]` to `t[1]`.

#### 2. Updating the Tree

- **Update Leaf**: Update the value at the leaf node.
- **Propagate Up**: Update the internal nodes by moving upwards.

```cpp
void update(int pos, int val, int n) {
    // Update the value at the leaf
    pos += n;
    t[pos] = val;
    // Update the internal nodes
    for (int i = pos / 2; i > 0; i /= 2) {
        t[i] = t[i * 2] + t[i * 2 + 1];
    }
}
```

- **Example**: To update position `4` to `88`:
  - Update `t[14]` (4 + 10).
  - Update parents: `t[7]`, `t[3]`, `t[1]`.

#### 3. Querying the Tree

- **Shift to Leaf Level**: Adjust the indices to the leaf level.
- **Traverse and Sum**: Traverse the range `[l, r]`, summing the relevant segments.

```cpp
int query(int l, int r, int n) {
    l += n; // Shift the index to the leaf level
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
```

- **Example**: Query the sum in range `[2, 5]`:
  - Adjust indices: `l = 12`, `r = 15`.
  - Traverse and sum relevant nodes: `t[12]`, `t[13]`, `t[15]`.

### Main Function

```cpp
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
```

### Summary

The iterative segment tree implementation involves:
- Building the tree bottom-up.
- Updating values with propagation upwards.
- Querying sums with efficient traversal.

This approach avoids recursion, making it suitable for handling large arrays without the risk of stack overflow.