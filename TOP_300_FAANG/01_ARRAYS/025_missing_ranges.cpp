/*
================================================================================
PROBLEM: Missing Ranges (LeetCode #163)
DIFFICULTY: Easy
PATTERN: Array / String Manipulation
COMPANIES: Amazon, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        long long next = lower;
        
        for (int num : nums) {
            if (num < next) continue;
            
            if (num == next) {
                next++;
                continue;
            }
            
            result.push_back(formatRange(next, num - 1));
            next = (long long)num + 1;
        }
        
        if (next <= upper) {
            result.push_back(formatRange(next, upper));
        }
        
        return result;
    }
    
    string formatRange(long long lower, long long upper) {
        if (lower == upper) {
            return to_string(lower);
        }
        return to_string(lower) + "->" + to_string(upper);
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {0, 1, 3, 50, 75};
    vector<int> nums2 = {};
    
    vector<string> result1 = sol.findMissingRanges(nums1, 0, 99);
    cout << "Missing ranges: ";
    for (string& s : result1) cout << s << " ";
    cout << endl;
    
    vector<string> result2 = sol.findMissingRanges(nums2, 1, 1);
    cout << "Missing ranges: ";
    for (string& s : result2) cout << s << " ";
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Summary Ranges (LeetCode #228)
2. Missing Number (LeetCode #268)
3. First Missing Positive (LeetCode #41)
4. Find All Numbers Disappeared (LeetCode #448)
5. Data Stream as Disjoint Intervals (LeetCode #352)
6. Merge Intervals (LeetCode #56)
7. Insert Interval (LeetCode #57)
8. Range Addition (LeetCode #370)
9. Range Addition II (LeetCode #598)
10. Count Integers in Intervals (LeetCode #2276)
*/
