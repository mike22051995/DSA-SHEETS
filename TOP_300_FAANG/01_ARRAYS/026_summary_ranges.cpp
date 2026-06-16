/*
================================================================================
PROBLEM: Summary Ranges (LeetCode #228)
DIFFICULTY: Easy
PATTERN: Two Pointers / Array
COMPANIES: Amazon, Google, Facebook, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        
        if (nums.empty()) return result;
        
        int start = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // Check if current number is the end of a range
            if (i + 1 == nums.size() || nums[i] + 1 != nums[i + 1]) {
                if (start == i) {
                    result.push_back(to_string(nums[start]));
                } else {
                    result.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
                }
                start = i + 1;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {0,1,2,4,5,7};
    vector<int> nums2 = {0,2,3,4,6,8,9};
    
    vector<string> result1 = sol.summaryRanges(nums1);
    cout << "Summary ranges: ";
    for (string& s : result1) cout << s << " ";
    cout << endl;
    
    vector<string> result2 = sol.summaryRanges(nums2);
    cout << "Summary ranges: ";
    for (string& s : result2) cout << s << " ";
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Missing Ranges (LeetCode #163)
2. Data Stream as Disjoint Intervals (LeetCode #352)
3. Merge Intervals (LeetCode #56)
4. Insert Interval (LeetCode #57)
5. Find Missing Observations (LeetCode #2028)
6. Missing Number (LeetCode #268)
7. First Missing Positive (LeetCode #41)
8. Range Addition (LeetCode #370)
9. Teemo Attacking (LeetCode #495)
10. Employee Free Time (LeetCode #759)
*/
