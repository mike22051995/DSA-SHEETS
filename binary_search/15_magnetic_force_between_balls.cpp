/*
PROBLEM: Magnetic Force Between Two Balls
Difficulty: Medium
Pattern: Binary Search on Answer

DESCRIPTION:
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls 
if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at 
position[i], Morty has m balls and needs to distribute the balls into the baskets such that 
the minimum magnetic force between any two balls is maximum.
Return the largest minimum magnetic force.

EXPLANATION:
Binary search on minimum distance:
- Sort positions first
- Min distance = 1, Max distance = (max - min) / (m - 1)
- For each distance, check if we can place m balls
- Find maximum distance that works

Time Complexity: O(n log n + n * log(max - min))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Place balls at positions 1, 4, and 7

Example 2:
Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: Place balls at positions 1 and 1000000000

Example 3:
Input: position = [1,2,8,4,9], m = 3
Output: 3
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int left = 1;
        int right = position.back() - position[0];
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canPlaceBalls(position, m, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
private:
    bool canPlaceBalls(vector<int>& position, int m, int minDist) {
        int count = 1;
        int lastPos = position[0];
        
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastPos >= minDist) {
                count++;
                lastPos = position[i];
                
                if (count >= m) return true;
            }
        }
        
        return count >= m;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> position1 = {1,2,3,4,7};
    cout << "Test 1: " << solution.maxDistance(position1, 3) << endl;
    
    // Test Case 2
    vector<int> position2 = {5,4,3,2,1,1000000000};
    cout << "Test 2: " << solution.maxDistance(position2, 2) << endl;
    
    // Test Case 3
    vector<int> position3 = {1,2,8,4,9};
    cout << "Test 3: " << solution.maxDistance(position3, 3) << endl;
    
    return 0;
}
