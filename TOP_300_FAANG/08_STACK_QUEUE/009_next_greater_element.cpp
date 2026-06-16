/*
================================================================================
PROBLEM: Next Greater Element I (LeetCode #496)
DIFFICULTY: Easy
PATTERN: Monotonic Stack
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;
        
        // Build next greater map for nums2
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        
        // Remaining elements have no next greater
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }
        
        // Build result for nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    
    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    
    cout << "Next greater elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Next Greater Element II (LeetCode #503) - circular array
2. Next Greater Element III (LeetCode #556)
3. Daily Temperatures (LeetCode #739)
4. Online Stock Span (LeetCode #901)
5. Sum of Subarray Minimums (LeetCode #907)
6. Remove K Digits (LeetCode #402)
7. Largest Rectangle in Histogram (LeetCode #84)
8. Maximal Rectangle (LeetCode #85)
9. Trapping Rain Water (LeetCode #42)
10. 132 Pattern (LeetCode #456)
*/
