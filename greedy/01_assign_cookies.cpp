/*
PROBLEM: Assign Cookies (LeetCode 455)
DIFFICULTY: Easy
PATTERN: Two Pointer + Greedy Matching

DESCRIPTION:
You have g children and s cookies. Each child has a greed factor g[i], which is the minimum size 
of a cookie that the child will be content with. Each cookie has a size s[j]. If s[j] >= g[i], 
we can assign the cookie j to the child i, and the child becomes content. 
Your goal is to maximize the number of content children.

INPUT:
- greed: array of integers representing children's greed factors
- cookies: array of integers representing cookie sizes

OUTPUT:
- Maximum number of content children

APPROACH:
1. Sort both arrays in ascending order
2. Use two pointers to match smallest available cookie to least greedy child
3. If current cookie satisfies current child, move to next child
4. Always move to next cookie

WHY GREEDY WORKS:
Giving the smallest sufficient cookie to the least greedy child leaves larger cookies 
for greedier children, maximizing total satisfied children.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& cookies) {
        // Sort both arrays
        sort(greed.begin(), greed.end());
        sort(cookies.begin(), cookies.end());
        
        int child = 0;  // Pointer for children
        int cookie = 0; // Pointer for cookies
        
        // Try to satisfy each child with available cookies
        while (child < greed.size() && cookie < cookies.size()) {
            if (cookies[cookie] >= greed[child]) {
                child++; // Child satisfied, move to next child
            }
            cookie++; // Move to next cookie regardless
        }
        
        return child; // Number of satisfied children
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> greed1 = {1, 2, 3};
    vector<int> cookies1 = {1, 1};
    cout << "Test 1 - Greed: [1,2,3], Cookies: [1,1]" << endl;
    cout << "Output: " << sol.findContentChildren(greed1, cookies1) << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Test Case 2
    vector<int> greed2 = {1, 2};
    vector<int> cookies2 = {1, 2, 3};
    cout << "Test 2 - Greed: [1,2], Cookies: [1,2,3]" << endl;
    cout << "Output: " << sol.findContentChildren(greed2, cookies2) << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test Case 3
    vector<int> greed3 = {10, 9, 8, 7};
    vector<int> cookies3 = {5, 6, 7, 8};
    cout << "Test 3 - Greed: [10,9,8,7], Cookies: [5,6,7,8]" << endl;
    cout << "Output: " << sol.findContentChildren(greed3, cookies3) << endl;
    cout << "Expected: 2" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n log n + m log m) where n = children, m = cookies (due to sorting)
SPACE COMPLEXITY: O(1) if we ignore sorting space, O(n + m) otherwise

KEY LEARNING:
- Greedy matching works when we can prove that local optimal leads to global optimal
- Sorting is often the first step in greedy algorithms
- Two-pointer technique is common in greedy array problems
*/
