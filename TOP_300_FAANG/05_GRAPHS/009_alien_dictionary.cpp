/*
================================================================================
PROBLEM: Alien Dictionary (LeetCode #269)
DIFFICULTY: Hard
PATTERN: Topological Sort
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;
        
        // Initialize all characters
        for (string& word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }
        
        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            
            // Check invalid case
            if (word1.length() > word2.length() && 
                word1.substr(0, word2.length()) == word2) {
                return "";
            }
            
            for (int j = 0; j < min(word1.length(), word2.length()); j++) {
                if (word1[j] != word2[j]) {
                    if (graph[word1[j]].find(word2[j]) == graph[word1[j]].end()) {
                        graph[word1[j]].insert(word2[j]);
                        indegree[word2[j]]++;
                    }
                    break;
                }
            }
        }
        
        // Topological sort (Kahn's algorithm)
        queue<char> q;
        for (auto& p : indegree) {
            if (p.second == 0) {
                q.push(p.first);
            }
        }
        
        string result = "";
        
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            result += c;
            
            for (char next : graph[c]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        return result.length() == indegree.size() ? result : "";
    }
};

int main() {
    Solution sol;
    vector<string> words1 = {"wrt","wrf","er","ett","rftt"};
    vector<string> words2 = {"z","x"};
    
    cout << "Alien order 1: " << sol.alienOrder(words1) << endl;
    cout << "Alien order 2: " << sol.alienOrder(words2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Course Schedule (LeetCode #207)
2. Course Schedule II (LeetCode #210)
3. Sequence Reconstruction (LeetCode #444)
4. Minimum Height Trees (LeetCode #310)
5. Verifying an Alien Dictionary (LeetCode #953)
6. Sort Items by Groups Respecting Dependencies (LeetCode #1203)
7. Find All Possible Recipes (LeetCode #2115)
8. Build Array Where You Can Find Maximum (LeetCode #1608)
9. Reconstruct Itinerary (LeetCode #332)
10. Parallel Courses (LeetCode #1136)
*/
