/*
PROBLEM: Custom Sort String (LeetCode 791)
===============================================
DESCRIPTION:
You are given two strings order and s. All the characters of order are unique 
and were sorted in some custom order previously. Permute the characters of s 
so that they match the order that order was sorted. Return any permutation of 
s that satisfies this property.

PATTERN: Custom Comparator / Counting Sort
DIFFICULTY: Medium
TIME COMPLEXITY: O(n + m) where n = s.length, m = order.length
SPACE COMPLEXITY: O(1) - constant 26 letters

INPUT:
order = "cba", s = "abcd"

OUTPUT:
"cbad"

EXAMPLE:
Input: order = "cba", s = "abcd"
Output: "cbad" (c, b, a appear in order, d at end)
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Approach 1: Custom Comparator
    string customSortString(string order, string s) {
        // Create map for ordering
        unordered_map<char, int> orderMap;
        for (int i = 0; i < order.length(); i++) {
            orderMap[order[i]] = i;
        }
        
        // Sort s based on custom order
        sort(s.begin(), s.end(), [&orderMap](char a, char b) {
            // Characters in order come first based on their position
            // Characters not in order come last (use large value)
            int posA = orderMap.count(a) ? orderMap[a] : 26;
            int posB = orderMap.count(b) ? orderMap[b] : 26;
            return posA < posB;
        });
        
        return s;
    }
    
    // Approach 2: Counting Sort (More efficient)
    string customSortStringCount(string order, string s) {
        // Count frequency of each character in s
        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }
        
        string result;
        
        // Add characters in order specified
        for (char c : order) {
            while (count[c - 'a'] > 0) {
                result += c;
                count[c - 'a']--;
            }
        }
        
        // Add remaining characters (not in order)
        for (int i = 0; i < 26; i++) {
            while (count[i] > 0) {
                result += char('a' + i);
                count[i]--;
            }
        }
        
        return result;
    }
    
    // Approach 3: Using stable_sort to maintain relative order
    string customSortStringStable(string order, string s) {
        unordered_map<char, int> orderMap;
        for (int i = 0; i < order.length(); i++) {
            orderMap[order[i]] = i;
        }
        
        stable_sort(s.begin(), s.end(), [&orderMap](char a, char b) {
            bool aInOrder = orderMap.count(a);
            bool bInOrder = orderMap.count(b);
            
            if (!aInOrder && !bInOrder) return false; // Maintain relative order
            if (!aInOrder) return false; // b comes first
            if (!bInOrder) return true;  // a comes first
            
            return orderMap[a] < orderMap[b];
        });
        
        return s;
    }
};

int main() {
    Solution sol;
    
    string order1 = "cba";
    string s1 = "abcd";
    cout << "Order: \"" << order1 << "\", String: \"" << s1 << "\"" << endl;
    cout << "Result (Comparator): \"" << sol.customSortString(order1, s1) << "\"" << endl;
    cout << "Result (Counting): \"" << sol.customSortStringCount(order1, s1) << "\"" << endl;
    
    string order2 = "cbafg";
    string s2 = "abcd";
    cout << "\nOrder: \"" << order2 << "\", String: \"" << s2 << "\"" << endl;
    cout << "Result (Comparator): \"" << sol.customSortString(order2, s2) << "\"" << endl;
    cout << "Result (Counting): \"" << sol.customSortStringCount(order2, s2) << "\"" << endl;
    
    return 0;
}

/*
EXPLANATION:
============
APPROACH 1: CUSTOM COMPARATOR WITH SORT
1. Create map: character → position in order
2. Sort string s using custom comparator
3. Characters in order sorted by their position
4. Characters not in order placed at end

Time: O(n log n)
Space: O(m) for map

APPROACH 2: COUNTING SORT (OPTIMAL)
1. Count frequency of each character in s
2. Build result by iterating through order
3. Add each character from order as many times as it appears
4. Add remaining characters (not in order) in any order

Time: O(n + m)
Space: O(1) - constant 26 characters

APPROACH 3: STABLE SORT
- Maintains relative order of characters not in order string
- More complex comparator logic

EXAMPLE WALKTHROUGH:
order = "cba", s = "abcd"

Counting approach:
1. Count: a=1, b=1, c=1, d=1
2. Process order:
   - 'c' in order, count[c]=1: add 'c', result = "c"
   - 'b' in order, count[b]=1: add 'b', result = "cb"
   - 'a' in order, count[a]=1: add 'a', result = "cba"
3. Add remaining: 'd' not in order, add 'd', result = "cbad"

WHY COUNTING SORT IS OPTIMAL:
- No comparison needed
- Linear time complexity
- Characters are limited (only lowercase letters)
- Direct bucket placement

COMPARISON:
Custom Comparator:
- O(n log n)
- More general
- Works with any comparison

Counting Sort:
- O(n)
- Optimal for this problem
- Limited to fixed character set

WHY THIS PATTERN IS IMPORTANT:
- Demonstrates custom ordering requirements
- Shows when counting sort beats comparison sort
- Common in string manipulation with constraints
- Used in: Reordering problems, priority-based arrangements
- Tests understanding of sorting trade-offs
*/
