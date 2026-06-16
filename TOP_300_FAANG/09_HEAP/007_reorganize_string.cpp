/*
================================================================================
PROBLEM: Reorganize String (LeetCode #767)
DIFFICULTY: Medium
PATTERN: Greedy / Heap
COMPANIES: Amazon, Facebook, Google, Microsoft
================================================================================
DESCRIPTION:
Rearrange a string so that no two adjacent characters are the same. If
impossible, return an empty string.

INPUT FORMAT:
- s: input string

OUTPUT FORMAT:
- reorganized string or empty string

APPROACH (HEAP):
- Count frequencies and use a max-heap by count.
- Always place the most frequent character, then reinsert the previous one.

CODE EXPLANATION:
- The heap stores (count, char) with the most frequent on top.
- prev holds the last used char; it is reinserted if it still has count.
- If the built string length matches input, it is valid; else return empty.

COMPLEXITY:
- Time: O(n log sigma)
- Space: O(sigma)

SAMPLE INPUT/OUTPUT:
1) s = "aab" -> "aba"
2) s = "aaab" -> ""
3) s = "vvvlo" -> "vlvov"
4) s = "aabb" -> "abab"
5) s = "aaabc" -> "abaca"
================================================================================
*/

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for (auto& p : freq) {
            pq.push({p.second, p.first});
        }
        
        string result = "";
        pair<int, char> prev = {-1, '#'};
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            result += curr.second;
            
            if (prev.first > 0) {
                pq.push(prev);
            }
            
            curr.first--;
            prev = curr;
        }
        
        return result.length() == s.length() ? result : "";
    }
    
    // Greedy approach
    string reorganizeStringGreedy(string s) {
        unordered_map<char, int> freq;
        char maxChar;
        int maxFreq = 0;
        
        for (char c : s) {
            freq[c]++;
            if (freq[c] > maxFreq) {
                maxFreq = freq[c];
                maxChar = c;
            }
        }
        
        if (maxFreq > (s.length() + 1) / 2) {
            return "";
        }
        
        string result(s.length(), ' ');
        int idx = 0;
        
        // Place most frequent character
        while (freq[maxChar]-- > 0) {
            result[idx] = maxChar;
            idx += 2;
        }
        
        // Place remaining characters
        for (auto& p : freq) {
            while (p.second-- > 0) {
                if (idx >= s.length()) idx = 1;
                result[idx] = p.first;
                idx += 2;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    cout << "Reorganized: " << sol.reorganizeString("aab") << endl;
    cout << "Reorganized: " << sol.reorganizeString("aaab") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Task Scheduler (LeetCode #621)
2. Rearrange String k Distance Apart (LeetCode #358)
3. Distant Barcodes (LeetCode #1054)
4. Longest Happy String (LeetCode #1405)
5. Maximum Number of Consecutive Values (LeetCode #1798)
6. Construct Target Array With Multiple Sums (LeetCode #1354)
7. Minimum Number of Refueling Stops (LeetCode #871)
8. IPO (LeetCode #502)
9. Find K Pairs with Smallest Sums (LeetCode #373)
10. Sort Characters By Frequency (LeetCode #451)
*/
