/*
================================================================================
PROBLEM: Assign Cookies (LeetCode #455)
DIFFICULTY: Easy
PATTERN: Greedy / Two Pointers
COMPANIES: Amazon, Microsoft, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int child = 0;
        int cookie = 0;
        
        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {
                child++;
            }
            cookie++;
        }
        
        return child;
    }
};

int main() {
    Solution sol;
    vector<int> g1 = {1,2,3};
    vector<int> s1 = {1,1};
    
    vector<int> g2 = {1,2};
    vector<int> s2 = {1,2,3};
    
    cout << "Content children: " << sol.findContentChildren(g1, s1) << endl;
    cout << "Content children: " << sol.findContentChildren(g2, s2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Two Sum II (LeetCode #167)
2. 3Sum (LeetCode #15)
3. 4Sum (LeetCode #18)
4. Meeting Rooms (LeetCode #252)
5. Non-overlapping Intervals (LeetCode #435)
6. Queue Reconstruction by Height (LeetCode #406)
7. Minimum Number of Arrows (LeetCode #452)
8. Partition Labels (LeetCode #763)
9. Candy (LeetCode #135)
10. Gas Station (LeetCode #134)
*/
