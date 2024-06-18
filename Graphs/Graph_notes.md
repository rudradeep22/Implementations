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
For weighed graphs prefereably  
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




