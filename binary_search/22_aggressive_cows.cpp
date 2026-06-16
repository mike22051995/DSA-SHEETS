/*
PROBLEM: Aggressive Cows
Difficulty: Hard
Pattern: Binary Search on Answer

DESCRIPTION:
Farmer John has built a new long barn with N stalls. The stalls are located at positions 
x1, x2, ..., xN. His C cows don't like the barn layout and become aggressive towards each 
other once put into a stall. To prevent the cows from hurting each other, John wants to 
assign the cows to the stalls, such that the minimum distance between any two of them is 
as large as possible. What is the largest minimum distance?

EXPLANATION:
Binary search on minimum distance:
- Sort stall positions
- Min distance = 1, Max distance = (max position - min position)
- For each distance, check if we can place all C cows
- Find maximum distance that works

Time Complexity: O(n log n + n * log(max - min))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: stalls = [1,2,4,8,9], cows = 3
Output: 3
Explanation: Place cows at positions 1, 4, and 8

Example 2:
Input: stalls = [1,2,8,4,9], cows = 3
Output: 3
Explanation: After sorting: [1,2,4,8,9], place at 1, 4, 8

Example 3:
Input: stalls = [5,4,3,2,1,1000000000], cows = 2
Output: 999999999
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int aggressiveCows(vector<int>& stalls, int cows) {
        sort(stalls.begin(), stalls.end());
        
        int left = 1;
        int right = stalls.back() - stalls[0];
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canPlaceCows(stalls, cows, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
private:
    bool canPlaceCows(vector<int>& stalls, int cows, int minDist) {
        int count = 1;
        int lastPos = stalls[0];
        
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= minDist) {
                count++;
                lastPos = stalls[i];
                
                if (count >= cows) return true;
            }
        }
        
        return count >= cows;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> stalls1 = {1,2,4,8,9};
    cout << "Test 1: " << solution.aggressiveCows(stalls1, 3) << endl;
    
    // Test Case 2
    vector<int> stalls2 = {1,2,8,4,9};
    cout << "Test 2: " << solution.aggressiveCows(stalls2, 3) << endl;
    
    // Test Case 3
    vector<int> stalls3 = {5,4,3,2,1,1000000000};
    cout << "Test 3: " << solution.aggressiveCows(stalls3, 2) << endl;
    
    return 0;
}
