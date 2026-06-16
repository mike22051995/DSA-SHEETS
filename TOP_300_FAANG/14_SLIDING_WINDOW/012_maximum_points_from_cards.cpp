/*
================================================================================
PROBLEM: Maximum Points You Can Obtain from Cards (LeetCode #1423)
DIFFICULTY: Medium
PATTERN: Sliding Window
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================

PROBLEM DESCRIPTION:
There are several cards arranged in a row, and each card has an associated
number of points. The points are given in the integer array cardPoints. In one
step, you can take one card from the beginning or from the end of the row. You
have to take exactly k cards. Return the maximum score you can obtain.

EXAMPLES:

Example 1:
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: Take 3 cards from beginning: 1+2+3=6 or from end: 6+1+1=8 or
mixed: 1+6+1=8 or 2+6+1=9 or 3+6+1=10 or 1+2+1=4 or 1+2+6=9 or 3+4+5=12 (best)

Example 2:
Input: cardPoints = [2,2,2], k = 2
Output: 4

Example 3:
Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55

PATTERN RECOGNITION:
Use this pattern when:
- Take elements from either end of array
- Find minimum/maximum subarray sum
- Sliding window to find minimum window of size n-k
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        
        // If k equals n, take all cards
        if (k == n) return totalSum;
        
        // Find minimum sum of subarray of size n-k
        int windowSize = n - k;
        int windowSum = 0;
        
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }
        
        int minWindowSum = windowSum;
        
        for (int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i] - cardPoints[i - windowSize];
            minWindowSum = min(minWindowSum, windowSum);
        }
        
        return totalSum - minWindowSum;
    }
    
    // Alternative: Take from both ends
    int maxScoreBothEnds(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        // Take all k cards from left
        int leftSum = 0;
        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }
        
        int maxScore = leftSum;
        
        // Try taking cards from right
        int rightSum = 0;
        for (int i = 0; i < k; i++) {
            leftSum -= cardPoints[k - 1 - i];
            rightSum += cardPoints[n - 1 - i];
            maxScore = max(maxScore, leftSum + rightSum);
        }
        
        return maxScore;
    }
};

int main() {
    Solution sol;
    
    vector<int> cards1 = {1,2,3,4,5,6,1};
    cout << "Max score (k=3): " << sol.maxScore(cards1, 3) << endl;
    
    vector<int> cards2 = {2,2,2};
    cout << "Max score (k=2): " << sol.maxScore(cards2, 2) << endl;
    
    vector<int> cards3 = {9,7,7,9,7,7,9};
    cout << "Max score (k=7): " << sol.maxScore(cards3, 7) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is array length
SPACE COMPLEXITY: O(1)

SIMILAR PROBLEMS:
1. Maximum Subarray (LeetCode #53)
2. Minimum Size Subarray Sum (LeetCode #209)
3. Longest Substring Without Repeating (LeetCode #3)
4. Minimum Window Substring (LeetCode #76)
5. Fruit Into Baskets (LeetCode #904)
6. Longest Repeating Character Replacement (LeetCode #424)
7. Max Consecutive Ones III (LeetCode #1004)
8. Grumpy Bookstore Owner (LeetCode #1052)
9. Diet Plan Performance (LeetCode #1176)
10. Count Number of Nice Subarrays (LeetCode #1248)
*/
