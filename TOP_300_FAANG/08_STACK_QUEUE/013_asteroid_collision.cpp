/*
================================================================================
PROBLEM: Asteroid Collision (LeetCode #735)
DIFFICULTY: Medium
PATTERN: Stack
COMPANIES: Amazon, Facebook, Microsoft, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        
        for (int asteroid : asteroids) {
            bool alive = true;
            
            while (!stk.empty() && asteroid < 0 && stk.top() > 0) {
                if (stk.top() < -asteroid) {
                    stk.pop();
                    continue;
                } else if (stk.top() == -asteroid) {
                    stk.pop();
                }
                
                alive = false;
                break;
            }
            
            if (alive) {
                stk.push(asteroid);
            }
        }
        
        vector<int> result(stk.size());
        for (int i = stk.size() - 1; i >= 0; i--) {
            result[i] = stk.top();
            stk.pop();
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> asteroids1 = {5, 10, -5};
    vector<int> asteroids2 = {8, -8};
    vector<int> asteroids3 = {10, 2, -5};
    
    vector<int> result1 = sol.asteroidCollision(asteroids1);
    cout << "Result: ";
    for (int x : result1) cout << x << " ";
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Can Place Flowers (LeetCode #605)
2. Remove All Adjacent Duplicates in String (LeetCode #1047)
3. Daily Temperatures (LeetCode #739)
4. Remove K Digits (LeetCode #402)
5. Minimum Add to Make Parentheses Valid (LeetCode #921)
6. Maximum Score of a Good Subarray (LeetCode #1793)
7. Robot Collisions (LeetCode #2751)
8. Remove Duplicate Letters (LeetCode #316)
9. Validate Stack Sequences (LeetCode #946)
10. Online Stock Span (LeetCode #901)
*/
