/*
================================================================================
PROBLEM: Maximum Swap (LeetCode #670)
DIFFICULTY: Medium
PATTERN: Greedy / Array
COMPANIES: Amazon, Facebook, Google, Microsoft
================================================================================

PROBLEM DESCRIPTION:
You are given an integer num. You can swap two digits at most once to get the
maximum valued number. Return the maximum valued number you can get.

EXAMPLES:

Example 1:
Input: num = 2736
Output: 7236
Explanation: Swap 2 and 7.

Example 2:
Input: num = 9973
Output: 9973
Explanation: Already the maximum.

Example 3:
Input: num = 98368
Output: 98863
Explanation: Swap 3 and 8.

PATTERN RECOGNITION:
Use this pattern when:
- One swap to maximize/minimize value
- Greedy approach finding best positions
- Track last occurrence of each digit
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.length();
        vector<int> last(10, -1);
        
        // Record last occurrence of each digit
        for (int i = 0; i < n; i++) {
            last[str[i] - '0'] = i;
        }
        
        // Find first position where we can swap with larger digit
        for (int i = 0; i < n; i++) {
            // Try to find larger digit from 9 down
            for (int d = 9; d > str[i] - '0'; d--) {
                if (last[d] > i) {
                    swap(str[i], str[last[d]]);
                    return stoi(str);
                }
            }
        }
        
        return num;
    }
};

int main() {
    Solution sol;
    
    cout << "2736 -> " << sol.maximumSwap(2736) << endl;
    cout << "9973 -> " << sol.maximumSwap(9973) << endl;
    cout << "98368 -> " << sol.maximumSwap(98368) << endl;
    cout << "1993 -> " << sol.maximumSwap(1993) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is number of digits
SPACE COMPLEXITY: O(1) - fixed size array for 10 digits

SIMILAR PROBLEMS:
1. Next Greater Element III (LeetCode #556)
2. Next Permutation (LeetCode #31)
3. Monotone Increasing Digits (LeetCode #738)
4. Largest Number At Least Twice (LeetCode #747)
5. Largest Number (LeetCode #179)
6. Remove K Digits (LeetCode #402)
7. Create Maximum Number (LeetCode #321)
8. Largest Time for Given Digits (LeetCode #949)
9. Maximize Number After K Swaps (Similar problem)
10. Minimum Number of K Consecutive Bit Flips (LeetCode #995)
*/
