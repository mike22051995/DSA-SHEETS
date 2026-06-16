/*
================================================================================
PROBLEM: Permutation Sequence (LeetCode #60)
DIFFICULTY: Hard
PATTERN: Math / Backtracking
COMPANIES: Amazon, Microsoft, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n);
        vector<int> numbers;
        
        factorial[0] = 1;
        for (int i = 1; i < n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }
        
        k--; // Convert to 0-indexed
        
        string result;
        
        for (int i = n; i >= 1; i--) {
            int index = k / factorial[i - 1];
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k -= index * factorial[i - 1];
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    cout << "3rd permutation of n=3: " << sol.getPermutation(3, 3) << endl;
    cout << "9th permutation of n=4: " << sol.getPermutation(4, 9) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Permutations (LeetCode #46)
2. Permutations II (LeetCode #47)
3. Next Permutation (LeetCode #31)
4. K-th Symbol in Grammar (LeetCode #779)
5. Find Kth Bit in Nth Binary String (LeetCode #1545)
6. Kth Smallest Instructions (LeetCode #1643)
7. Kth Smallest Amount With Single Denomination (LeetCode #3116)
8. Ugly Number II (LeetCode #264)
9. Super Ugly Number (LeetCode #313)
10. Combinations (LeetCode #77)
*/
