/*
PROBLEM: Boats to Save People
---------------------------------------------------------------------------
You are given an array people where people[i] is the weight of the ith person, 
and an infinite number of boats where each boat can carry a maximum weight 
of limit. Each boat carries at most two people at the same time, provided 
the sum of their weights is at most limit. Return the minimum number of 
boats to carry every given person.

PATTERN: Sorting + Opposite Direction Two Pointers (Greedy)
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat carries both people (1 + 2).

Example 2:
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats: (1,2), (2), (3)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;
        
        while (left <= right) {
            // Try to pair heaviest with lightest
            if (people[left] + people[right] <= limit) {
                left++;  // Both can fit in one boat
            }
            right--;  // Heaviest person takes a boat
            boats++;
        }
        
        return boats;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> people1 = {1, 2};
    int limit1 = 3;
    cout << "Test 1: " << sol.numRescueBoats(people1, limit1) << endl;
    
    // Test case 2
    vector<int> people2 = {3, 2, 2, 1};
    int limit2 = 3;
    cout << "Test 2: " << sol.numRescueBoats(people2, limit2) << endl;
    
    return 0;
}
