# Graph Problems for FAANG Interview Preparation

## 📚 Complete Collection of 30 Essential Graph Problems

This repository contains **30 carefully selected graph problems** covering all major patterns and algorithms asked in FAANG interviews. Each problem includes:
- ✅ Detailed problem description
- ✅ Complete C++ implementation
- ✅ Complexity analysis
- ✅ Input/output examples
- ✅ Step-by-step explanation

---

## 🎯 How to Use This Repository

1. **Start with Easy problems (1-10)** to build fundamentals
2. **Progress to Medium problems (11-20)** for core patterns
3. **Master Hard problems (21-30)** for advanced techniques
4. Compile and run: `g++ -std=c++17 filename.cpp -o output && ./output`

---

## 📊 Problems by Difficulty

### **EASY (Problems 1-10)**

| # | Problem | Pattern | Complexity |
|---|---------|---------|------------|
| 01 | [DFS Traversal](01_dfs_traversal.cpp) | DFS Basics | O(V+E) |
| 02 | [BFS Traversal](02_bfs_traversal.cpp) | BFS Basics | O(V+E) |
| 03 | [Number of Islands](03_number_of_islands.cpp) | DFS on Grid | O(M×N) |
| 04 | [Detect Cycle - Undirected](04_detect_cycle_undirected.cpp) | DFS + Parent Tracking | O(V+E) |
| 05 | [Detect Cycle - Directed](05_detect_cycle_directed.cpp) | DFS + Recursion Stack | O(V+E) |
| 06 | [Flood Fill](06_flood_fill.cpp) | DFS on Grid | O(M×N) |
| 07 | [Clone Graph](07_clone_graph.cpp) | DFS + HashMap | O(V+E) |
| 08 | [Is Graph Bipartite](08_is_graph_bipartite.cpp) | BFS Coloring | O(V+E) |
| 09 | [01 Matrix](09_01_matrix.cpp) | Multi-Source BFS | O(M×N) |
| 10 | [Surrounded Regions](10_surrounded_regions.cpp) | DFS from Boundary | O(M×N) |

---

### **MEDIUM (Problems 11-20)**

| # | Problem | Pattern | Complexity |
|---|---------|---------|------------|
| 11 | [Topological Sort - BFS](11_topological_sort_bfs.cpp) | Kahn's Algorithm | O(V+E) |
| 12 | [Topological Sort - DFS](12_topological_sort_dfs.cpp) | DFS + Stack | O(V+E) |
| 13 | [Course Schedule](13_course_schedule.cpp) | Cycle Detection / Topo Sort | O(V+E) |
| 14 | [Course Schedule II](14_course_schedule_ii.cpp) | Topological Sort | O(V+E) |
| 15 | [Number of Provinces](15_number_of_provinces.cpp) | Connected Components | O(N²) |
| 16 | [Rotting Oranges](16_rotting_oranges.cpp) | Multi-Source BFS | O(M×N) |
| 17 | [Pacific Atlantic Water Flow](17_pacific_atlantic_water_flow.cpp) | Multi-Source DFS | O(M×N) |
| 18 | [Union-Find](18_union_find.cpp) | Disjoint Set Union | O(α(N)) |
| 19 | [Connected Components](19_connected_components_undirected.cpp) | Union-Find | O(E×α(N)) |
| 20 | [Graph Valid Tree](20_graph_valid_tree.cpp) | Union-Find / Cycle Detection | O(E×α(N)) |

---

### **HARD (Problems 21-30)**

| # | Problem | Pattern | Complexity |
|---|---------|---------|------------|
| 21 | [Dijkstra's Algorithm](21_dijkstra_shortest_path.cpp) | Shortest Path | O((V+E)logV) |
| 22 | [Bellman-Ford](22_bellman_ford.cpp) | Negative Weight Paths | O(V×E) |
| 23 | [Network Delay Time](23_network_delay_time.cpp) | Dijkstra Application | O((V+E)logV) |
| 24 | [Cheapest Flights K Stops](24_cheapest_flights_k_stops.cpp) | Modified Dijkstra | O(E×K×logE) |
| 25 | [Prim's MST](25_prims_mst.cpp) | Minimum Spanning Tree | O(E×logV) |
| 26 | [Kruskal's MST](26_kruskals_mst.cpp) | MST + Union-Find | O(E×logE) |
| 27 | [Strongly Connected Components](27_strongly_connected_components.cpp) | Kosaraju's Algorithm | O(V+E) |
| 28 | [Articulation Points](28_articulation_points.cpp) | DFS + Discovery Time | O(V+E) |
| 29 | [Bridges in Graph](29_bridges_in_graph.cpp) | DFS + Low Link | O(V+E) |
| 30 | [Word Ladder](30_word_ladder.cpp) | BFS on Implicit Graph | O(M²×N) |

---

## 🔑 Key Patterns Covered

### **1. Graph Traversal**
- ✅ DFS (Depth-First Search)
- ✅ BFS (Breadth-First Search)
- ✅ Multi-Source BFS/DFS

### **2. Cycle Detection**
- ✅ Undirected Graph (DFS with parent)
- ✅ Directed Graph (DFS with recursion stack)

### **3. Topological Sorting**
- ✅ Kahn's Algorithm (BFS)
- ✅ DFS-based approach

### **4. Shortest Path**
- ✅ Dijkstra's Algorithm (non-negative weights)
- ✅ Bellman-Ford (negative weights)
- ✅ BFS for unweighted graphs

### **5. Minimum Spanning Tree**
- ✅ Prim's Algorithm (greedy)
- ✅ Kruskal's Algorithm (Union-Find)

### **6. Union-Find (Disjoint Set)**
- ✅ Path Compression
- ✅ Union by Rank
- ✅ Connected Components

### **7. Advanced Algorithms**
- ✅ Strongly Connected Components (Kosaraju)
- ✅ Articulation Points & Bridges
- ✅ Bipartite Graph Checking

### **8. Grid Problems**
- ✅ Island problems
- ✅ Matrix traversal
- ✅ Boundary-based DFS/BFS

---

## 💡 Interview Tips

### **Before Your Interview (This Week!)**

1. **Day 1-2**: Master Easy problems (1-10)
   - Focus on DFS and BFS fundamentals
   - Practice grid traversal patterns

2. **Day 3-4**: Tackle Medium problems (11-20)
   - Learn topological sort both ways
   - Master Union-Find data structure

3. **Day 5-6**: Conquer Hard problems (21-30)
   - Understand shortest path algorithms
   - Practice MST and SCC

4. **Day 7 (Before Interview)**: Review & Practice
   - Revise all patterns
   - Solve 2-3 random problems from each category

### **Common Interview Questions**
- "Find if a path exists" → BFS/DFS
- "Shortest path" → BFS (unweighted) or Dijkstra (weighted)
- "Detect cycle" → DFS with coloring
- "All possible paths" → Backtracking DFS
- "Minimum cost/edges" → MST or Shortest Path
- "Group connected items" → Union-Find or DFS

### **Problem-Solving Template**

```cpp
// 1. Understand the problem
// 2. Identify the pattern
// 3. Choose appropriate algorithm
// 4. Consider edge cases
// 5. Implement and test
```

---

## 🎓 Pattern Recognition Guide

| If the problem asks... | Use this pattern |
|------------------------|------------------|
| "Visit all nodes" | DFS or BFS |
| "Shortest path (unweighted)" | BFS |
| "Shortest path (weighted)" | Dijkstra or Bellman-Ford |
| "Detect cycle" | DFS with colors/stack |
| "Ordering with dependencies" | Topological Sort |
| "Group connected components" | Union-Find or DFS |
| "Minimum cost to connect all" | MST (Prim/Kruskal) |
| "Is graph connected?" | DFS/BFS or Union-Find |
| "Can be divided into 2 groups?" | Bipartite Check |
| "Critical connections" | Bridges/Articulation Points |

---

## 📖 Study Resources

### **Must-Know Concepts**
1. Graph Representation (Adjacency List vs Matrix)
2. Time & Space Complexity Analysis
3. Recursion and Backtracking
4. Queue and Stack operations
5. Priority Queue (Heap)

### **Common Graph Problems in FAANG**
- **Amazon**: Island problems, DFS/BFS, Connected Components
- **Google**: Shortest Path, Topological Sort, MST
- **Facebook**: Graph Coloring, Bipartite, Clone Graph
- **Apple**: Grid traversal, Union-Find
- **Netflix**: Recommendation systems (Graph traversal)

---

## ⚡ Quick Reference

### **Time Complexities**
- DFS/BFS: O(V + E)
- Dijkstra: O((V + E) log V)
- Bellman-Ford: O(V × E)
- Union-Find: O(α(N)) ≈ O(1)
- Topological Sort: O(V + E)
- MST (Prim/Kruskal): O(E log V) or O(E log E)

### **Space Complexities**
- Adjacency List: O(V + E)
- Adjacency Matrix: O(V²)
- DFS Recursion: O(V) stack space
- BFS Queue: O(V) queue space

---

## 🚀 Good Luck with Your Interview!

**Remember:**
- Clarify the problem before coding
- Think aloud during the interview
- Start with a brute force approach
- Optimize step by step
- Test with edge cases
- Communicate your thought process

**You've got this! All the best for Friday! 💪**

---

## 📝 Notes
- All code is tested and working
- Uses C++17 standard
- Includes detailed comments
- Ready for compilation

**Last Updated**: December 2025
**Total Problems**: 30
**Patterns Covered**: 8+
**Estimated Study Time**: 7 days
