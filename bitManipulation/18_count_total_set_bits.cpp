/*
PROBLEM: Count Total Set Bits from 1 to N
===========================================
Count the total number of set bits in binary representation of 
all numbers from 1 to n.

APPROACH:
- Pattern observation: bits at position i repeat every 2^(i+1) numbers
- For each bit position, count how many times it's set from 1 to n
- Use formula: (n+1) / (2^(i+1)) * 2^i + max(0, (n+1) % (2^(i+1)) - 2^i)

PATTERN: Bit Counting with Pattern Recognition

INPUT/OUTPUT:
Input: n = 5
Output: 7
Explanation: 
1(001) = 1 bit
2(010) = 1 bit
3(011) = 2 bits
4(100) = 1 bit
5(101) = 2 bits
Total = 7 bits

TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        int powerOf2 = 1;
        
        // Process each bit position
        while (powerOf2 <= n) {
            // Total pairs of 0s and 1s
            int totalPairs = (n + 1) / (powerOf2 * 2);
            count += totalPairs * powerOf2;
            
            // Remaining numbers
            int remainder = (n + 1) % (powerOf2 * 2);
            if (remainder > powerOf2) {
                count += remainder - powerOf2;
            }
            
            powerOf2 <<= 1; // Move to next bit position
        }
        
        return count;
    }
    
    // Brute force for verification
    int countSetBitsBruteForce(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            int num = i;
            while (num > 0) {
                count += num & 1;
                num >>= 1;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    int n1 = 5;
    cout << "Input: " << n1 << endl;
    cout << "Output (Optimized): " << sol.countSetBits(n1) << endl;
    cout << "Output (Brute Force): " << sol.countSetBitsBruteForce(n1) << endl;
    cout << "Explanation: 1(1)+2(1)+3(2)+4(1)+5(2) = 7" << endl << endl;
    
    // Test Case 2
    int n2 = 10;
    cout << "Input: " << n2 << endl;
    cout << "Output (Optimized): " << sol.countSetBits(n2) << endl;
    cout << "Output (Brute Force): " << sol.countSetBitsBruteForce(n2) << endl << endl;
    
    // Test Case 3
    int n3 = 15;
    cout << "Input: " << n3 << endl;
    cout << "Output (Optimized): " << sol.countSetBits(n3) << endl;
    cout << "Output (Brute Force): " << sol.countSetBitsBruteForce(n3) << endl;
    
    return 0;
}
