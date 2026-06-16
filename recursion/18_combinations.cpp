/*
PROBLEM: Combinations
---------------------------------------------------------------------------
Given two integers n and k, return all possible combinations of k numbers 
chosen from the range [1, n].

DIFFICULTY: Medium
PATTERN: Backtracking (Choose K from N)
TIME COMPLEXITY: O(C(n,k) * k) where C(n,k) is binomial coefficient
SPACE COMPLEXITY: O(k) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]

Example 2:
Input: n = 1, k = 1
Output: [[1]]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(n, k, 1, current, result);
        return result;
    }
    
private:
    void backtrack(int n, int k, int start, vector<int>& current,
                   vector<vector<int>>& result) {
        // Base case: found k elements
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        
        // Try all numbers from start to n
        for (int i = start; i <= n; i++) {
            current.push_back(i);               // choose
            backtrack(n, k, i + 1, current, result); // explore
            current.pop_back();                 // unchoose
        }
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    int n1 = 4, k1 = 2;
    vector<vector<int>> result1 = sol.combine(n1, k1);
    cout << "Test 1: ";
    for (auto& comb : result1) {
        cout << "[";
        for (int i = 0; i < comb.size(); i++) {
            cout << comb[i] << (i < comb.size() - 1 ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    
    // Test case 2
    int n2 = 1, k2 = 1;
    vector<vector<int>> result2 = sol.combine(n2, k2);
    cout << "Test 2: Total combinations = " << result2.size() << endl;
    
    return 0;
}
