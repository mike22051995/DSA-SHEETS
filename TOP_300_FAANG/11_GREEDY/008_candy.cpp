/*
================================================================================
PROBLEM: Candy (LeetCode #135)
DIFFICULTY: Hard
PATTERN: Greedy
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        
        // Left to right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        // Right to left pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        int total = 0;
        for (int candy : candies) {
            total += candy;
        }
        
        return total;
    }
};

int main() {
    Solution sol;
    vector<int> ratings1 = {1,0,2};
    vector<int> ratings2 = {1,2,2};
    
    cout << "Minimum candies: " << sol.candy(ratings1) << endl;
    cout << "Minimum candies: " << sol.candy(ratings2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Trapping Rain Water (LeetCode #42)
2. Gas Station (LeetCode #134)
3. Increasing Triplet Subsequence (LeetCode #334)
4. Jump Game II (LeetCode #45)
5. Maximum Subarray (LeetCode #53)
6. Best Time to Buy and Sell Stock II (LeetCode #122)
7. Queue Reconstruction by Height (LeetCode #406)
8. Corporate Flight Bookings (LeetCode #1109)
9. Minimum Number of Increments (LeetCode #1827)
10. Maximize Score After N Operations (LeetCode #1799)
*/
