/*
PROBLEM: Minimum Operations to Make Array Equal (LeetCode 1551)
DIFFICULTY: Easy
PATTERN: Mathematical Greedy (Median/Mean Strategy)

DESCRIPTION:
You have an array arr of length n where arr[i] = (2 * i) + 1 for all valid values of i 
(i.e., 0 <= i < n). In one operation, you can select two indices x and y where 0 <= x, y < n 
and subtract 1 from arr[x] and add 1 to arr[y] (i.e., arr[x] -= 1 and arr[y] += 1).
The goal is to make all the elements of the array equal. Return the minimum number of operations.

INPUT:
- n: length of array (array is [1, 3, 5, 7, ..., 2n-1])

OUTPUT:
- Minimum operations to make all elements equal

APPROACH:
Array is [1, 3, 5, ..., 2n-1]
- All elements should become equal to median (which equals n)
- Sum of differences from median gives answer
- Mathematical formula: for n even: n²/4, for n odd: (n²-1)/4

WHY GREEDY WORKS:
Optimal target is always the median. Moving values toward median minimizes total operations.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int minOperations(int n) {
        // Formula derivation:
        // Array: [1, 3, 5, ..., 2n-1]
        // Target: each element becomes n
        // Operations = sum of |arr[i] - n| / 2
        
        // Mathematical formula:
        if (n % 2 == 0) {
            return (n * n) / 4;
        } else {
            return (n * n - 1) / 4;
        }
    }
    
    // Alternative: simulation approach (to understand the logic)
    int minOperationsSimulation(int n) {
        int operations = 0;
        int target = n;  // Target value (median)
        
        // Only need to count first half (symmetry)
        for (int i = 0; i < n / 2; i++) {
            int value = 2 * i + 1;
            operations += target - value;
        }
        
        return operations;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    cout << "Test 1 - n=3 (array [1,3,5])" << endl;
    cout << "Output: " << sol.minOperations(3) << endl;
    cout << "Expected: 2 (make all elements 3)" << endl << endl;
    
    // Test Case 2
    cout << "Test 2 - n=6 (array [1,3,5,7,9,11])" << endl;
    cout << "Output: " << sol.minOperations(6) << endl;
    cout << "Expected: 9 (make all elements 6)" << endl << endl;
    
    // Test Case 3
    cout << "Test 3 - n=4 (array [1,3,5,7])" << endl;
    cout << "Output: " << sol.minOperations(4) << endl;
    cout << "Expected: 4 (make all elements 4)" << endl << endl;
    
    // Test Case 4
    cout << "Test 4 - n=1 (array [1])" << endl;
    cout << "Output: " << sol.minOperations(1) << endl;
    cout << "Expected: 0" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(1) - direct formula
SPACE COMPLEXITY: O(1)

KEY LEARNING:
- Sometimes greedy problems have closed-form mathematical solutions
- Median is optimal target for "make all elements equal" problems
- Look for patterns and symmetry to derive formulas
- Simulation helps understand, but math gives O(1) solution
- This pattern appears in "equalize array" type problems
*/
