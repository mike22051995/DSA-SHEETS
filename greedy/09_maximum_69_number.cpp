/*
PROBLEM: Maximum 69 Number (LeetCode 1323)
DIFFICULTY: Easy
PATTERN: Greedy Single Change Optimization

DESCRIPTION:
You are given a positive integer num consisting only of digits 6 and 9.
Return the maximum number you can get by changing at most one digit (6 becomes 9, or 9 becomes 6).

INPUT:
- num: positive integer with only 6s and 9s

OUTPUT:
- Maximum number after at most one digit change

APPROACH:
1. To maximize the number, change the leftmost 6 to 9
2. More significant digits have greater impact
3. No benefit in changing 9 to 6 (decreases value)

WHY GREEDY WORKS:
Changing the leftmost 6 to 9 gives maximum increase because it affects 
the most significant position.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maximum69Number(int num) {
        string s = to_string(num);
        
        // Find leftmost '6' and change it to '9'
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '6') {
                s[i] = '9';
                break;  // Change only one digit
            }
        }
        
        return stoi(s);
    }
    
    // Alternative: without string conversion
    int maximum69NumberMath(int num) {
        int temp = num;
        int digitPosition = 0;
        int leftmost6Position = -1;
        
        // Find position of leftmost 6 from right
        while (temp > 0) {
            if (temp % 10 == 6) {
                leftmost6Position = digitPosition;
            }
            temp /= 10;
            digitPosition++;
        }
        
        // If found a 6, add 3 * 10^position to change it to 9
        if (leftmost6Position != -1) {
            int powerOf10 = 1;
            for (int i = 0; i < leftmost6Position; i++) {
                powerOf10 *= 10;
            }
            num += 3 * powerOf10;
        }
        
        return num;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    cout << "Test 1 - Input: 9669" << endl;
    cout << "Output: " << sol.maximum69Number(9669) << endl;
    cout << "Expected: 9969" << endl << endl;
    
    // Test Case 2
    cout << "Test 2 - Input: 9996" << endl;
    cout << "Output: " << sol.maximum69Number(9996) << endl;
    cout << "Expected: 9999" << endl << endl;
    
    // Test Case 3
    cout << "Test 3 - Input: 9999" << endl;
    cout << "Output: " << sol.maximum69Number(9999) << endl;
    cout << "Expected: 9999" << endl << endl;
    
    // Test Case 4
    cout << "Test 4 - Input: 6666" << endl;
    cout << "Output: " << sol.maximum69Number(6666) << endl;
    cout << "Expected: 9666" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(d) where d is number of digits
SPACE COMPLEXITY: O(d) for string approach, O(1) for math approach

KEY LEARNING:
- Greedy optimization: make change at most significant position
- Position matters in optimization problems
- Single change problems often have greedy solutions
- Consider both string and mathematical approaches
*/
