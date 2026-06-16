/*
================================================================================
PROBLEM: Container With Most Water (LeetCode #11)
DIFFICULTY: Medium
PATTERN: Two Pointers
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
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
            int width = right - left;
            int h = min(height[left], height[right]);
            maxWater = max(maxWater, width * h);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};

int main() {
    Solution sol;
    vector<int> height1 = {1,8,6,2,5,4,8,3,7};
    vector<int> height2 = {1,1};
    
    cout << "Max area: " << sol.maxArea(height1) << endl;
    cout << "Max area: " << sol.maxArea(height2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Trapping Rain Water (LeetCode #42)
2. Trapping Rain Water II (LeetCode #407)
3. Largest Rectangle in Histogram (LeetCode #84)
4. Maximal Rectangle (LeetCode #85)
5. Maximal Square (LeetCode #221)
6. Pour Water (LeetCode #755)
7. Max Increase to Keep City Skyline (LeetCode #807)
8. Container With Most Water II
9. Product of Array Except Self (LeetCode #238)
10. Gas Station (LeetCode #134)
*/
