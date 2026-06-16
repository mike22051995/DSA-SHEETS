/*
PROBLEM: Two Sum II - Input Array Is Sorted
---------------------------------------------------------------------------
Given a 1-indexed array of integers that is already sorted in non-decreasing 
order, find two numbers such that they add up to a specific target number.
Return the indices of the two numbers (1-indexed) as an integer array.

You must use only constant extra space.

PATTERN: Opposite Direction Two Pointers
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2.

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore, index1 = 1, index2 = 3.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        
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
        
        return {-1, -1}; // No solution found
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(numbers1, target1);
    cout << "Test 1: [" << result1[0] << ", " << result1[1] << "]" << endl;
    
    // Test case 2
    vector<int> numbers2 = {2, 3, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(numbers2, target2);
    cout << "Test 2: [" << result2[0] << ", " << result2[1] << "]" << endl;
    
    return 0;
}
