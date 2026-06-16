/*
PROBLEM: Boats to Save People (LeetCode 881)
DIFFICULTY: Medium
PATTERN: Two Pointer Greedy Pairing

DESCRIPTION:
You are given an array people where people[i] is the weight of the ith person, and an 
infinite number of boats where each boat can carry a maximum weight of limit. Each boat 
carries at most two people at the same time, provided the sum of the weight of those 
people is at most limit. Return the minimum number of boats to carry every given person.

INPUT:
- people: array of person weights
- limit: maximum weight per boat

OUTPUT:
- Minimum number of boats needed

APPROACH:
1. Sort people by weight
2. Use two pointers: lightest and heaviest
3. Try to pair lightest with heaviest
4. If they fit together, move both pointers
5. If not, heaviest goes alone

WHY GREEDY WORKS:
Pairing lightest with heaviest maximizes boat utilization. If heaviest can't 
pair with lightest, it can't pair with anyone.
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
            // Check if lightest and heaviest can share a boat
            if (people[left] + people[right] <= limit) {
                left++;   // Lightest person gets on boat
                right--;  // Heaviest person gets on boat
            } else {
                right--;  // Only heaviest person gets on boat
            }
            boats++;  // One boat used either way
        }
        
        return boats;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> people1 = {1, 2};
    cout << "Test 1 - People: [1,2], Limit: 3" << endl;
    cout << "Output: " << sol.numRescueBoats(people1, 3) << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Test Case 2
    vector<int> people2 = {3, 2, 2, 1};
    cout << "Test 2 - People: [3,2,2,1], Limit: 3" << endl;
    cout << "Output: " << sol.numRescueBoats(people2, 3) << endl;
    cout << "Expected: 3" << endl << endl;
    
    // Test Case 3
    vector<int> people3 = {3, 5, 3, 4};
    cout << "Test 3 - People: [3,5,3,4], Limit: 5" << endl;
    cout << "Output: " << sol.numRescueBoats(people3, 5) << endl;
    cout << "Expected: 4" << endl << endl;
    
    // Test Case 4
    vector<int> people4 = {5, 1, 4, 2};
    cout << "Test 4 - People: [5,1,4,2], Limit: 6" << endl;
    cout << "Output: " << sol.numRescueBoats(people4, 6) << endl;
    cout << "Expected: 2" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n log n) due to sorting
SPACE COMPLEXITY: O(1)

KEY LEARNING:
- Two pointer after sorting: common greedy pattern
- Pair extremes (smallest with largest)
- If extremes don't work, no point trying middle values
- Similar to container with most water problem
- Pattern: optimal pairing problems
*/
