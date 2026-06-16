/*
PROBLEM: Maximum Number of Removable Characters
Difficulty: Hard
Pattern: Binary Search on Answer

DESCRIPTION:
You are given two strings s and p where p is a subsequence of s. You are also given a distinct 
0-indexed integer array removable containing a subset of indices of s (s is also 0-indexed).
You want to choose an integer k (0 <= k <= removable.length) such that, after removing k 
characters from s using the first k indices in removable, p is still a subsequence of s.
Return the maximum k you can choose.

EXPLANATION:
Binary search on k:
- For each k, remove first k characters and check if p is still subsequence
- Use two-pointer technique to check subsequence
- Find maximum k where p remains subsequence

Time Complexity: O(n * log(removable.length))
Space Complexity: O(n)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: s = "abcacb", p = "ab", removable = [3,1,0]
Output: 2
Explanation: After removing indices 3 and 1, "ab" is still subsequence

Example 2:
Input: s = "abcbddddd", p = "abcd", removable = [3,2,1,4,5,6]
Output: 1
Explanation: After removing index 3, "abcd" is still subsequence

Example 3:
Input: s = "abcab", p = "abc", removable = [0,1,2,3,4]
Output: 0
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0;
        int right = removable.size();
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (isSubsequence(s, p, removable, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
private:
    bool isSubsequence(string& s, string& p, vector<int>& removable, int k) {
        unordered_set<int> removed;
        
        for (int i = 0; i < k; i++) {
            removed.insert(removable[i]);
        }
        
        int j = 0;
        for (int i = 0; i < s.length() && j < p.length(); i++) {
            if (removed.find(i) == removed.end() && s[i] == p[j]) {
                j++;
            }
        }
        
        return j == p.length();
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    string s1 = "abcacb", p1 = "ab";
    vector<int> removable1 = {3,1,0};
    cout << "Test 1: " << solution.maximumRemovals(s1, p1, removable1) << endl;
    
    // Test Case 2
    string s2 = "abcbddddd", p2 = "abcd";
    vector<int> removable2 = {3,2,1,4,5,6};
    cout << "Test 2: " << solution.maximumRemovals(s2, p2, removable2) << endl;
    
    // Test Case 3
    string s3 = "abcab", p3 = "abc";
    vector<int> removable3 = {0,1,2,3,4};
    cout << "Test 3: " << solution.maximumRemovals(s3, p3, removable3) << endl;
    
    return 0;
}
