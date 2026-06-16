/*
================================================================================
PROBLEM: Evaluate Division (LeetCode #399)
DIFFICULTY: Medium
PATTERN: Graph / DFS / Union Find
COMPANIES: Amazon, Google, Facebook, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        
        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }
        
        vector<double> result;
        
        for (auto& query : queries) {
            string start = query[0];
            string end = query[1];
            
            if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
                result.push_back(-1.0);
            } else if (start == end) {
                result.push_back(1.0);
            } else {
                unordered_set<string> visited;
                double ans = dfs(graph, start, end, visited);
                result.push_back(ans);
            }
        }
        
        return result;
    }
    
    double dfs(unordered_map<string, vector<pair<string, double>>>& graph,
               string curr, string target, unordered_set<string>& visited) {
        if (curr == target) return 1.0;
        
        visited.insert(curr);
        
        for (auto& [neighbor, val] : graph[curr]) {
            if (visited.find(neighbor) == visited.end()) {
                double result = dfs(graph, neighbor, target, visited);
                if (result != -1.0) {
                    return result * val;
                }
            }
        }
        
        return -1.0;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    
    vector<double> results = sol.calcEquation(equations, values, queries);
    
    cout << "Results: ";
    for (double res : results) {
        cout << res << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Accounts Merge (LeetCode #721)
2. Redundant Connection (LeetCode #684)
3. Sentence Similarity II (LeetCode #737)
4. Most Stones Removed (LeetCode #947)
5. Satisfiability of Equality Equations (LeetCode #990)
6. Number of Connected Components (LeetCode #323)
7. Minimize Malware Spread (LeetCode #924)
8. Smallest String With Swaps (LeetCode #1202)
9. Check if Move is Legal (LeetCode #1958)
10. Find All People With Secret (LeetCode #2092)
*/
