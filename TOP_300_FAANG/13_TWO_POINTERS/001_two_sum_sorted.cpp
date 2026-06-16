/*
================================================================================
PROBLEM: Two Sum II - Input Array Is Sorted (LeetCode #167)
DIFFICULTY: Medium
PATTERN: Two Pointers
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            
            if (sum == target) {
                return {left + 1, right + 1}; // 1-indexed
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {2,7,11,15};
    auto result = sol.twoSum(numbers, 9);
    
    cout << "Two sum indices: [" << result[0] << "," << result[1] << "]" << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Two Sum (LeetCode #1)
2. 3Sum (LeetCode #15)
3. 3Sum Closest (LeetCode #16)
4. 4Sum (LeetCode #18)
5. Remove Duplicates from Sorted Array (LeetCode #26)
6. Container With Most Water (LeetCode #11)
7. Trapping Rain Water (LeetCode #42)
8. Valid Palindrome (LeetCode #125)
9. Sort Colors (LeetCode #75)
10. Move Zeroes (LeetCode #283)
*/
