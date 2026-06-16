/*
================================================================================
PROBLEM: Subarrays with K Different Integers (LeetCode #992)
DIFFICULTY: Hard
PATTERN: Sliding Window
COMPANIES: Amazon, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int left = 0;
        int result = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (count[nums[right]]++ == 0) {
                k--;
            }
            
            while (k < 0) {
                if (--count[nums[left]] == 0) {
                    k++;
                }
                left++;
            }
            
            result += right - left + 1;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,2,1,2,3};
    vector<int> nums2 = {1,2,1,3,4};
    
    cout << "Subarrays with K=2 distinct: " << sol.subarraysWithKDistinct(nums1, 2) << endl;
    cout << "Subarrays with K=3 distinct: " << sol.subarraysWithKDistinct(nums2, 3) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Longest Substring with At Most K Distinct (LeetCode #340)
2. Longest Substring with At Most Two Distinct (LeetCode #159)
3. Count Number of Nice Subarrays (LeetCode #1248)
4. Binary Subarrays With Sum (LeetCode #930)
5. Fruit Into Baskets (LeetCode #904)
6. Max Consecutive Ones III (LeetCode #1004)
7. Number of Substrings Containing All Three (LeetCode #1358)
8. Count Vowel Substrings (LeetCode #2062)
9. Count Complete Subarrays (LeetCode #2799)
10. Number of Equal Count Substrings (LeetCode #2067)
*/
