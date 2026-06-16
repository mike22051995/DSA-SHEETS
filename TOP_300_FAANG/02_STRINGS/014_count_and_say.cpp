/*
================================================================================
PROBLEM: Count and Say (LeetCode #38)
DIFFICULTY: Medium
PATTERN: String Manipulation / Simulation
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string result = "1";
        
        for (int i = 2; i <= n; i++) {
            result = getNext(result);
        }
        
        return result;
    }
    
    string getNext(string s) {
        string result = "";
        int i = 0;
        
        while (i < s.length()) {
            char current = s[i];
            int count = 0;
            
            while (i < s.length() && s[i] == current) {
                count++;
                i++;
            }
            
            result += to_string(count) + current;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    for (int i = 1; i <= 6; i++) {
        cout << "n=" << i << ": " << sol.countAndSay(i) << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Encode and Decode Strings (LeetCode #271)
2. String Compression (LeetCode #443)
3. Look-and-Say Sequence (Mathematical)
4. Decode Ways (LeetCode #91)
5. Integer to English Words (LeetCode #273)
6. Decode String (LeetCode #394)
7. Number of Atoms (LeetCode #726)
8. Compress String (CTCI)
9. Run Length Encoding
10. ZigZag Conversion (LeetCode #6)
*/
