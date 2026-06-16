/*
PROBLEM: Fruit Into Baskets
---------------------------------------------------------------------------
You are visiting a farm with a single row of fruit trees. Each tree has a 
type denoted by an integer. You have two baskets, and each basket can hold 
any quantity of fruit, but you want each basket to only hold one type of fruit.
Find the maximum number of fruits you can collect.

PATTERN: Sliding Window (At Most K Distinct)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: fruits = [1,2,1]
Output: 3
Explanation: We can collect all 3 fruits using 2 baskets for types 1 and 2.

Example 2:
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can collect [1,2,2]. Types 1 and 2 in two baskets.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket; // fruit type -> count
        int left = 0;
        int maxFruits = 0;
        
        for (int right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;
            
            // Shrink window if more than 2 types
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            
            maxFruits = max(maxFruits, right - left + 1);
        }
        
        return maxFruits;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> fruits1 = {1, 2, 1};
    cout << "Test 1: " << sol.totalFruit(fruits1) << endl;
    
    // Test case 2
    vector<int> fruits2 = {0, 1, 2, 2};
    cout << "Test 2: " << sol.totalFruit(fruits2) << endl;
    
    return 0;
}
