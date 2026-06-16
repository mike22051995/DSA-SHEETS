/*
================================================================================
PROBLEM: Container With Most Water (LeetCode #11)
DIFFICULTY: Medium
PATTERN: Two Pointers
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
You are given an integer array height of length n. There are n vertical lines 
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the 
container contains the most water.

Return the maximum amount of water a container can store.
Notice that you may not slant the container.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Finding optimal pair from array ends
2. Area/volume maximization problems
3. Can eliminate one pointer based on logic
4. Greedy approach works

Key Indicators:
- "Two elements" forming something
- Maximize area/volume/distance
- Starting from both ends makes sense
- Can prove why moving one pointer

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: Lines at index 1 and 8 form container
Area = min(8,7) * (8-1) = 7 * 7 = 49

Example 2:
Input: height = [1,1]
Output: 1
Explanation: Only one container possible
Area = min(1,1) * (1-0) = 1

Example 3:
Input: height = [4,3,2,1,4]
Output: 16
Explanation: Lines at index 0 and 4
Area = min(4,4) * (4-0) = 4 * 4 = 16

================================================================================
EXPLANATION:

Approach: Two Pointers
- Start with widest container (left=0, right=n-1)
- Area = min(height[left], height[right]) * (right - left)
- Move the pointer with smaller height inward
  
Why move smaller height?
- Width decreases as we move inward
- To potentially increase area, we need taller line
- Moving taller pointer can only decrease area

Algorithm:
1. Initialize left=0, right=n-1, maxArea=0
2. While left < right:
   - Calculate current area
   - Update maxArea if needed
   - Move pointer with smaller height
3. Return maxArea

Time Complexity: O(n) - single pass with two pointers
Space Complexity: O(1)

================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        
        while (left < right) {
            // Calculate current area
            int width = right - left;
            int h = min(height[left], height[right]);
            int currentArea = width * h;
            
            maxWater = max(maxWater, currentArea);
            
            // Move the pointer with smaller height
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
    
    // Brute Force - For comparison
    int maxAreaBruteForce(vector<int>& height) {
        int maxWater = 0;
        int n = height.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int width = j - i;
                int h = min(height[i], height[j]);
                maxWater = max(maxWater, width * h);
            }
        }
        
        return maxWater;
    }
};

void runTest(vector<int> height, string testName) {
    Solution sol;
    int result = sol.maxArea(height);
    
    cout << testName << ": " << endl;
    cout << "Input: [";
    for (int i = 0; i < height.size(); i++) {
        cout << height[i];
        if (i < height.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Maximum Water: " << result << endl;
    cout << "-------------------" << endl;
}

int main() {
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    runTest(height1, "Test 1");
    
    vector<int> height2 = {1, 1};
    runTest(height2, "Test 2");
    
    vector<int> height3 = {4, 3, 2, 1, 4};
    runTest(height3, "Test 3");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Trapping Rain Water (LeetCode #42) - Hard
   - Calculate trapped water between bars
   - Use two pointers or stack

2. Largest Rectangle in Histogram (LeetCode #84) - Hard
   - Find maximum rectangle area
   - Use stack

3. Maximal Rectangle (LeetCode #85) - Hard
   - 2D version of histogram problem

4. Product of Array Except Self (LeetCode #238) - Medium
   - Two-pass technique

5. Maximum Width Ramp (LeetCode #962) - Medium
   - Find max i-j where nums[i] <= nums[j]

6. Best Time to Buy and Sell Stock (LeetCode #121) - Easy
   - Similar max difference logic

7. Minimum Size Subarray Sum (LeetCode #209) - Medium
   - Sliding window variant

8. 3Sum (LeetCode #15) - Medium
   - Two pointers after fixing one element

9. Remove Duplicates from Sorted Array (LeetCode #26) - Easy
   - Two pointers for in-place

10. Two Sum II (LeetCode #167) - Medium
    - Two pointers on sorted array

================================================================================
KEY INSIGHTS:
================================================================================

1. Why Two Pointers Works:
   - Start with maximum width
   - Only move pointer with smaller height
   - Moving taller pointer can't improve area

2. Proof of Correctness:
   - We don't miss optimal solution
   - Each move eliminates impossible cases
   - Greedy choice is safe

3. Common Mistake:
   - Moving both pointers
   - Moving taller height pointer
   - Not considering width * height formula

4. Follow-up Questions:
   - What if you can use k containers?
   - What if heights can be negative?
   - 3D version of the problem?

================================================================================
*/
