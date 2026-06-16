/*
================================================================================
PROBLEM: Partition Labels (LeetCode #763)
DIFFICULTY: Medium
PATTERN: Greedy / Two Pointers
COMPANIES: Amazon, Facebook, Microsoft, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;
        
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i]] = i;
        }
        
        vector<int> result;
        int start = 0;
        int end = 0;
        
        for (int i = 0; i < s.length(); i++) {
            end = max(end, lastIndex[s[i]]);
            
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string s = "ababcbacadefegdehijhklij";
    
    vector<int> result = sol.partitionLabels(s);
    
    cout << "Partition sizes: ";
    for (int size : result) {
        cout << size << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Merge Intervals (LeetCode #56)
2. Interval List Intersections (LeetCode #986)
3. Longest Substring Without Repeating (LeetCode #3)
4. Split Array into Consecutive Subsequences (LeetCode #659)
5. Maximum Number of Events Attended (LeetCode #1353)
6. Maximum Number of Events Attended II (LeetCode #1751)
7. Find All Anagrams in String (LeetCode #438)
8. Group Anagrams (LeetCode #49)
9. Maximum Sum Obtained of Any Permutation (LeetCode #1589)
10. Minimum Number of K Consecutive Bit Flips (LeetCode #995)
*/
