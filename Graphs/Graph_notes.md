# Graph Notes  
### Detect cycle in Directed Graph  
Cycle exists in graph only if back edge is present in the graph. Use DFS to traverse graph and keep record of the vertices in recursion stack at present by backtracking. If current vertex is already there in `rec_stack` then cycle exists. Otherwise no.

### Topological Sorting (Kahn's BFS)
Linear ordering of vertices so that for every directed edge `uv`, `u` comes before `v` in the ordering. Only for **Directed Acyclic Graphs**.   
**Algorithm :**  
* Calculate in degree of each vertex present in DAG, and `visited_nodes = 0`
* Pick all vertices with `in_degree = 0` and push them into queue.
* Remove a vertex from the queue and do: 
    * `visited_nodes++`
    * `in_degree--` for all adjacent vertices
    * if `indegree = 0` push those vertices into queue
* Repeat above till queue is empty
* if `visited_nodes != n`, then toposort is not possible, cycle exists 

So, this algo can also be used to find cycle in directed graph.

### Dijkstra's algo for shortest path  
For weighed graphs prefereably. Doesn't work with negative weight edges.   
**Algorithm :**
* Create a set `sptSet` (shortest path tree set) that keeps track of vertices included in shortest path tree, i.e., whose minimum distance from source is calculated and finalized. Initially, this set is empty.
* Assign `dis` value to all vertices as `INF` and for source as 0.
* While `sptSet` doesn't have all vertices:   
    * Pick a vertex `u` that is not in `sptSet` but has min `dis` value.
    * Add `u` to `sptSet`.
    * Update `dis` for all adjacent vertices of `u`. For any such vertex `v`,  
     `dis[v] = min(dis[v], dis[u] + w[u,v])`,  
        where `w[u,v]` is the weight of edge `uv`.

Since at every step we need to find the vertex with minimum distance from the source vertex from the set of vertices currently not added to the `sptSet`, so we can use a `min_heap` for easier and efficient implementation.

### Minimum Spanning Tree (Prim's algo)
It is a Greedy algo. A group of edges that connect 2set of vertices in a graph is called a **cut**. So, at every step of Prim’s algorithm, we find a **cut** (of two sets, one contains the vertices already included in MST and other contains rest of the vertices), pick the minimum weight edge from the cut and include this vertex to MST Set (the set that contains already included vertices).

**Algorithm :**
* Create a set `mstSet` to keep track of vertices in MST. Initially, it's empty.
* Assign a `key` value to all vertices of the graph as `INF`, but first vertex as 0. We'll begin with first one.
* While `mstSet` doesn't contain all vertices: 
    * Pick a vertex `u`, not in `mstSet`, that has minimum `key` value.
    * Push `u` into `mstSet`.
    * Update `key` for all adjacent vertices. For a vertex `v`,  
        `key[v] = min(key[v], w[u, v])`

The `key` helps us choose the minimum weight of the cut.

### Kosaraju's algo for Strongly Connected Components
A directed component is strongly connected if there is a path between all pairs of vertices. 
**Algorithm :**
* Create a stack `st` and do **DFS** trversal on the graph. In **DFS** traversal, after calling recursive **DFS** for adjacent vertices of a vertex, push the vertex to `st`.
* Reverse all directions of edges to get the _transposed graph_.
* Pop a vertex `v` from the stack `st`. Do **DFS** from v as source and this prints the SCC containing v.
* Count all such **DFS** calls to get the number of SCCs.

### Bellman Ford algo for shortest path
Problem is similar to **Dijkstra** but while **Dijkstra** works with TC = `O(VlogV)`, Bellman-ford takes `O(VE)`. But, this also works for graphs with negative weight edges, unlike **Dijkstra**.  
If there is a negative weight cycle, then shortest distances are not calculated, negative weight cycle is reported.  

**Algorithm :**  
* Create a `dis[]` with all distances as `INF` except source vertex as 0
* Do the following `|V|-1` times:
    * for each edge `u-v`,  `dis[v] = min(dis[v], dis[u] + w[u,v])`
* Now check for negative weight cycle. For each edge `u-v` check:   
    `dis[v] > dis[u] + w[u,v]`  
    If true, then Graph **has** negative weight cycle 

### Articulation points (or Cut vertices)  
A vertex in undirected graph is Articulation point if removing it disconnects the graph or increases the number of components.

**Intuition :** Consider the DFS tree. A vertex `u` is an articulation point if :  
    <ol>
        <li>`u` is the root and it has at least 2 children</li>
        <li>`u` has a child `v` such that any vertex in the subtree rooted at `v` does not have a back-edge to any ancestor of `u`</li>
        <li>Leaf is never articulation point</li>
    </ol>
**Algorithm :**  
* Do DFS traversal of the graph. Maintain a `parent[]` array, where `parent[u]` stores parent of vertex `u`.
* 1st case is easy to check, check if `u` is a root and if it has 2 or more children
* For 2nd case, maintain a `disc[]` array to store discovery time of vertices. For every node `u`, we need to find out the earliest visited vertex (the vertex with minimum discovery time) that can be reached from subtree rooted with u. So we maintain an additional array `low[]` which is defined as follows.   
`low[u] = min(disc[u], disc[w])`  
where `w` is an ancestor of `u` and there is a back edge from 
some descendant of `u` to `w`.







