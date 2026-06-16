/*
PROBLEM: Largest Number (LeetCode 179)
===============================================
DESCRIPTION:
Given a list of non-negative integers, arrange them such that they form the 
largest number and return it as a string.

PATTERN: Custom Comparator Sorting
DIFFICULTY: Medium
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)

INPUT:
Array of non-negative integers

OUTPUT:
String representing the largest number

EXAMPLE:
Input: [10,2]
Output: "210"

Input: [3,30,34,5,9]
Output: "9534330"
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert numbers to strings
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }
        
        // Custom comparator: compare concatenations
        // For a and b, if ab > ba, then a should come before b
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        // Handle edge case: all zeros
        if (strs[0] == "0") return "0";
        
        // Concatenate all strings
        string result;
        for (const string& s : strs) {
            result += s;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {10, 2};
    cout << "Input: ";
    for (int num : nums1) cout << num << " ";
    cout << "\nOutput: " << sol.largestNumber(nums1) << endl;
    
    vector<int> nums2 = {3, 30, 34, 5, 9};
    cout << "\nInput: ";
    for (int num : nums2) cout << num << " ";
    cout << "\nOutput: " << sol.largestNumber(nums2) << endl;
    
    vector<int> nums3 = {0, 0};
    cout << "\nInput: ";
    for (int num : nums3) cout << num << " ";
    cout << "\nOutput: " << sol.largestNumber(nums3) << endl;
    
    return 0;
}

/*
EXPLANATION:
============
KEY INSIGHT:
- We need custom comparison, not standard numeric or lexicographic
- For two numbers a and b, compare concatenations: "ab" vs "ba"
- If "ab" > "ba", then a should come before b

EXAMPLE:
Numbers: [3, 30, 34, 5, 9]

Comparisons:
- 3 vs 30: "330" > "303" → 3 before 30
- 3 vs 34: "334" < "343" → 34 before 3
- 34 vs 5: "345" < "534" → 5 before 34
- 5 vs 9: "59" < "95" → 9 before 5

Sorted order: [9, 5, 34, 3, 30]
Result: "9534330"

WHY THIS WORKS:
- If a + b > b + a, then putting a before b gives larger result
- This comparison is transitive (required for sorting)
- Greedy approach: local optimal choices lead to global optimum

EDGE CASES:
1. All zeros [0, 0, 0]: Return "0" not "000"
2. Single element [5]: Return "5"
3. Same digits [3, 30]: Need careful comparison

PROOF OF TRANSITIVITY:
If a+b > b+a and b+c > c+b, then a+c > c+a
This ensures the comparator is valid for sorting

CUSTOM COMPARATOR:
Lambda function: [](const string& a, const string& b) { return a + b > b + a; }
- Takes two strings
- Returns true if a should come before b
- Uses string concatenation for comparison

WHY THIS PATTERN IS IMPORTANT:
- Demonstrates power of custom comparators
- Non-intuitive sorting criteria
- Common in problems requiring special ordering
- Tests understanding of sorting fundamentals
- Used in: meeting room ordering, event scheduling with custom rules
- Frequent in FAANG interviews
*/
