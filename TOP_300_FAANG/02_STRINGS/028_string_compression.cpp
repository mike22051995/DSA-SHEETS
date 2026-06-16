/*
================================================================================
PROBLEM: String Compression (LeetCode #443)
DIFFICULTY: Medium
PATTERN: Two Pointers / String
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================

PROBLEM DESCRIPTION:
Given an array of characters chars, compress it using the following algorithm:
Begin with an empty string s. For each group of consecutive repeating characters:
- If the group's length is 1, append the character to s.
- Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be
stored in the input character array chars. Return the new length of the array.

EXAMPLES:

Example 1:
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, chars = ["a","2","b","2","c","3"]

Example 2:
Input: chars = ["a"]
Output: Return 1, chars = ["a"]

Example 3:
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, chars = ["a","b","1","2"]

PATTERN RECOGNITION:
Use this pattern when:
- In-place string modification
- Run-length encoding
- Two pointers for read and write positions
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int read = 0;
        
        while (read < chars.size()) {
            char currentChar = chars[read];
            int count = 0;
            
            // Count consecutive characters
            while (read < chars.size() && chars[read] == currentChar) {
                read++;
                count++;
            }
            
            // Write character
            chars[write++] = currentChar;
            
            // Write count if > 1
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }
        
        return write;
    }
};

int main() {
    Solution sol;
    
    vector<char> chars1 = {'a','a','b','b','c','c','c'};
    int len1 = sol.compress(chars1);
    cout << "Length: " << len1 << ", Result: ";
    for (int i = 0; i < len1; i++) {
        cout << chars1[i];
    }
    cout << endl;
    
    vector<char> chars2 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    int len2 = sol.compress(chars2);
    cout << "Length: " << len2 << ", Result: ";
    for (int i = 0; i < len2; i++) {
        cout << chars2[i];
    }
    cout << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is array length
SPACE COMPLEXITY: O(1) in-place modification

SIMILAR PROBLEMS:
1. Count and Say (LeetCode #38)
2. Encode and Decode Strings (LeetCode #271)
3. Design Compressed String Iterator (LeetCode #604)
4. Length of Last Word (LeetCode #58)
5. Run-Length Encoding (Classic problem)
6. String to Integer (atoi) (LeetCode #8)
7. ZigZag Conversion (LeetCode #6)
8. Compare Version Numbers (LeetCode #165)
9. Valid Word Abbreviation (LeetCode #408)
10. Restore IP Addresses (LeetCode #93)
*/
