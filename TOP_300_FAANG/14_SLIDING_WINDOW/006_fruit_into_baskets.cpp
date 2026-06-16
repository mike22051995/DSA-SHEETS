/*
================================================================================
PROBLEM: Fruit Into Baskets (LeetCode #904)
DIFFICULTY: Medium
PATTERN: Sliding Window
COMPANIES: Amazon, Facebook, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int left = 0;
        int maxFruits = 0;
        
        for (int right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;
            
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            
            maxFruits = max(maxFruits, right - left + 1);
        }
        
        return maxFruits;
    }
};

int main() {
    Solution sol;
    vector<int> fruits1 = {1,2,1};
    vector<int> fruits2 = {0,1,2,2};
    vector<int> fruits3 = {1,2,3,2,2};
    
    cout << "Max fruits: " << sol.totalFruit(fruits1) << endl;
    cout << "Max fruits: " << sol.totalFruit(fruits2) << endl;
    cout << "Max fruits: " << sol.totalFruit(fruits3) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Longest Substring with At Most K Distinct (LeetCode #340)
2. Longest Substring with At Most Two Distinct (LeetCode #159)
3. Subarrays with K Different Integers (LeetCode #992)
4. Max Consecutive Ones III (LeetCode #1004)
5. Minimum Window Substring (LeetCode #76)
6. Longest Repeating Character Replacement (LeetCode #424)
7. Find All Anagrams in String (LeetCode #438)
8. Permutation in String (LeetCode #567)
9. Substring with Concatenation (LeetCode #30)
10. Grumpy Bookstore Owner (LeetCode #1052)
*/
