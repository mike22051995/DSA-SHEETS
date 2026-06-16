/*
PROBLEM: Candy (LeetCode 135)
DIFFICULTY: Hard
PATTERN: Two-Pass Greedy with Neighbor Constraints

DESCRIPTION:
There are n children standing in a line. Each child is assigned a rating value given in array ratings.
You are giving candies to these children subjected to the following requirements:
- Each child must have at least one candy
- Children with a higher rating get more candies than their neighbors
Return the minimum number of candies you need to have to distribute.

INPUT:
- ratings: array of ratings for each child

OUTPUT:
- Minimum candies needed

APPROACH:
1. Initialize all children with 1 candy
2. Left to right pass: if rating[i] > rating[i-1], candies[i] = candies[i-1] + 1
3. Right to left pass: if rating[i] > rating[i+1], candies[i] = max(candies[i], candies[i+1] + 1)
4. Sum all candies

WHY GREEDY WORKS:
Two-pass ensures both left and right neighbor constraints are satisfied.
Taking max in second pass preserves first pass results.
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        
        vector<int> candies(n, 1);  // Everyone gets at least 1 candy
        
        // Left to right: ensure right neighbor constraint
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        
        // Right to left: ensure left neighbor constraint
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }
        
        // Sum all candies
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> ratings1 = {1, 0, 2};
    cout << "Test 1 - Ratings: [1,0,2]" << endl;
    cout << "Output: " << sol.candy(ratings1) << endl;
    cout << "Expected: 5 (candies: [2,1,2])" << endl << endl;
    
    // Test Case 2
    vector<int> ratings2 = {1, 2, 2};
    cout << "Test 2 - Ratings: [1,2,2]" << endl;
    cout << "Output: " << sol.candy(ratings2) << endl;
    cout << "Expected: 4 (candies: [1,2,1])" << endl << endl;
    
    // Test Case 3
    vector<int> ratings3 = {1, 3, 2, 2, 1};
    cout << "Test 3 - Ratings: [1,3,2,2,1]" << endl;
    cout << "Output: " << sol.candy(ratings3) << endl;
    cout << "Expected: 7 (candies: [1,3,2,1,1] or [1,3,1,2,1])" << endl << endl;
    
    // Test Case 4
    vector<int> ratings4 = {1, 2, 3, 4, 5};
    cout << "Test 4 - Ratings: [1,2,3,4,5]" << endl;
    cout << "Output: " << sol.candy(ratings4) << endl;
    cout << "Expected: 15 (candies: [1,2,3,4,5])" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) - two passes through array
SPACE COMPLEXITY: O(n) for candies array

KEY LEARNING:
- Two-pass greedy: handle bidirectional constraints separately
- First pass handles one direction, second pass handles other
- Use max in second pass to preserve first pass results
- Classic hard greedy problem
- Pattern: multi-directional constraint satisfaction
- Very common in Google/Facebook interviews
*/
