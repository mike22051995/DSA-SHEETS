/*
================================================================================
PROBLEM: Boats to Save People (LeetCode #881)
DIFFICULTY: Medium
PATTERN: Two Pointers / Greedy
COMPANIES: Amazon, Microsoft, Google
================================================================================

PROBLEM DESCRIPTION:
You are given an array people where people[i] is the weight of the ith person,
and an infinite number of boats where each boat can carry a maximum weight of
limit. Each boat carries at most two people at the same time, provided the sum
of the weight of those people is at most limit. Return the minimum number of
boats to carry every given person.

EXAMPLES:

Example 1:
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)

Example 2:
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)

Example 3:
Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)

PATTERN RECOGNITION:
Use this pattern when:
- Pair elements to meet constraint
- Greedy matching with two pointers
- Sort then match from extremes
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
            // Try to pair lightest with heaviest
            if (people[left] + people[right] <= limit) {
                left++;
            }
            right--;
            boats++;
        }
        
        return boats;
    }
};

int main() {
    Solution sol;
    
    vector<int> people1 = {1,2};
    cout << "Boats needed: " << sol.numRescueBoats(people1, 3) << endl;
    
    vector<int> people2 = {3,2,2,1};
    cout << "Boats needed: " << sol.numRescueBoats(people2, 3) << endl;
    
    vector<int> people3 = {3,5,3,4};
    cout << "Boats needed: " << sol.numRescueBoats(people3, 5) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n log n) for sorting
SPACE COMPLEXITY: O(1) or O(n) depending on sort implementation

SIMILAR PROBLEMS:
1. Two Sum (LeetCode #1)
2. Two Sum II (LeetCode #167)
3. 3Sum (LeetCode #15)
4. 4Sum (LeetCode #18)
5. Valid Triangle Number (LeetCode #611)
6. Container With Most Water (LeetCode #11)
7. Trapping Rain Water (LeetCode #42)
8. Sort Colors (LeetCode #75)
9. Remove Duplicates from Sorted Array (LeetCode #26)
10. Minimize Maximum Pair Sum (LeetCode #1877)
*/
