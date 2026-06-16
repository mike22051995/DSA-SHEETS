/*
PROBLEM: Minimum XOR Value Pair
=================================
Find the minimum XOR value of any pair in an array.

APPROACH:
- Sort the array
- Minimum XOR will be between adjacent elements in sorted array
- XOR all adjacent pairs and find minimum

PATTERN: XOR Optimization with Sorting

INPUT/OUTPUT:
Input: arr = [9, 5, 3]
Output: 2
Explanation: (3 XOR 5) = 6, (5 XOR 9) = 12, (3 XOR 9) = 10
Minimum is between 5 and 3 after sorting: 3 XOR 5 = 6
Actually: arr sorted = [3,5,9], min(3^5, 5^9) = min(6,12) = 6
Wait, let me recalculate: 3=011, 5=101, 3^5=110=6

Input: arr = [0, 2, 4, 8]
Output: 0
Explanation: 0 XOR any number gives that number, but 4^0=4, etc
Actually minimum is between adjacent: 0^2=2, 2^4=6, 4^8=12, min=2

TIME COMPLEXITY: O(n log n) - sorting
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minXOR(vector<int>& arr) {
        // Sort the array
        sort(arr.begin(), arr.end());
        
        int minXor = INT_MAX;
        
        // Check XOR of adjacent elements
        for (int i = 0; i < arr.size() - 1; i++) {
            int xorVal = arr[i] ^ arr[i + 1];
            minXor = min(minXor, xorVal);
        }
        
        return minXor;
    }
    
    // Brute force approach for verification
    int minXORBruteForce(vector<int>& arr) {
        int minXor = INT_MAX;
        
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int xorVal = arr[i] ^ arr[j];
                minXor = min(minXor, xorVal);
            }
        }
        
        return minXor;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> arr1 = {9, 5, 3};
    cout << "Input: [9,5,3]" << endl;
    cout << "Output (Optimized): " << sol.minXOR(arr1) << endl;
    cout << "Output (Brute Force): " << sol.minXORBruteForce({9, 5, 3}) << endl;
    cout << "Explanation: After sorting [3,5,9], min XOR = 3^5 = 6" << endl << endl;
    
    // Test Case 2
    vector<int> arr2 = {0, 2, 4, 8};
    cout << "Input: [0,2,4,8]" << endl;
    cout << "Output (Optimized): " << sol.minXOR(arr2) << endl;
    cout << "Output (Brute Force): " << sol.minXORBruteForce({0, 2, 4, 8}) << endl;
    cout << "Explanation: Adjacent pairs give min XOR" << endl << endl;
    
    // Test Case 3
    vector<int> arr3 = {12, 4, 6, 2};
    cout << "Input: [12,4,6,2]" << endl;
    cout << "Output (Optimized): " << sol.minXOR(arr3) << endl;
    cout << "Output (Brute Force): " << sol.minXORBruteForce({12, 4, 6, 2}) << endl;
    cout << "Explanation: After sorting [2,4,6,12], 4^6=2 is minimum" << endl;
    
    return 0;
}
