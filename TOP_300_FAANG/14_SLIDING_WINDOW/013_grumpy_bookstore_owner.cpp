/*
================================================================================
PROBLEM: Grumpy Bookstore Owner (LeetCode #1052)
DIFFICULTY: Medium
PATTERN: Sliding Window
COMPANIES: Amazon, Google
================================================================================

PROBLEM DESCRIPTION:
There is a bookstore owner that has a store open for n minutes. Every minute,
some number of customers enter the store. You are given an integer array
customers of length n where customers[i] is the number of customers that enter
at the start of the ith minute. All minutes are numbered 0 to n - 1.

There is also another integer array grumpy of length n where grumpy[i] is:
- 1 if the bookstore owner is grumpy during the ith minute, or
- 0 otherwise.

When the bookstore owner is grumpy, customers entering during that minute are
not satisfied. The owner can suppress their grumpiness for a continuous segment
of minutes. Return the maximum number of customers that can be satisfied.

EXAMPLES:

Example 1:
Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
Output: 16

Example 2:
Input: customers = [1], grumpy = [0], minutes = 1
Output: 1

PATTERN RECOGNITION:
Use this pattern when:
- Maximize gain in a fixed-size window
- Sliding window to find best position
- Add unsatisfied customers in window to base satisfaction
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        
        // Calculate base satisfaction (when not grumpy)
        int baseSatisfied = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                baseSatisfied += customers[i];
            }
        }
        
        // Find max additional customers in any window of size 'minutes'
        int maxAdditional = 0;
        int currentAdditional = 0;
        
        // Initial window
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                currentAdditional += customers[i];
            }
        }
        maxAdditional = currentAdditional;
        
        // Slide window
        for (int i = minutes; i < n; i++) {
            // Add right element if grumpy
            if (grumpy[i] == 1) {
                currentAdditional += customers[i];
            }
            
            // Remove left element if grumpy
            if (grumpy[i - minutes] == 1) {
                currentAdditional -= customers[i - minutes];
            }
            
            maxAdditional = max(maxAdditional, currentAdditional);
        }
        
        return baseSatisfied + maxAdditional;
    }
};

int main() {
    Solution sol;
    
    vector<int> customers1 = {1,0,1,2,1,1,7,5};
    vector<int> grumpy1 = {0,1,0,1,0,1,0,1};
    cout << "Max satisfied: " << sol.maxSatisfied(customers1, grumpy1, 3) << endl;
    
    vector<int> customers2 = {1};
    vector<int> grumpy2 = {0};
    cout << "Max satisfied: " << sol.maxSatisfied(customers2, grumpy2, 1) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is array length
SPACE COMPLEXITY: O(1)

SIMILAR PROBLEMS:
1. Maximum Points from Cards (LeetCode #1423)
2. Max Consecutive Ones III (LeetCode #1004)
3. Longest Repeating Character Replacement (LeetCode #424)
4. Minimum Size Subarray Sum (LeetCode #209)
5. Longest Substring Without Repeating (LeetCode #3)
6. Fruit Into Baskets (LeetCode #904)
7. Subarray Product Less Than K (LeetCode #713)
8. Find All Anagrams (LeetCode #438)
9. Permutation in String (LeetCode #567)
10. Diet Plan Performance (LeetCode #1176)
*/
