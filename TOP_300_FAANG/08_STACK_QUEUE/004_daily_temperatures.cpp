/*
================================================================================
PROBLEM: Daily Temperatures (LeetCode #739)
DIFFICULTY: Medium
PATTERN: Monotonic Stack
COMPANIES: Amazon, Facebook, Google, Microsoft, Bloomberg
================================================================================
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st; // Store indices
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                result[prevIndex] = i - prevIndex;
            }
            st.push(i);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    auto result = sol.dailyTemperatures(temperatures);
    
    cout << "Days to warmer: ";
    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Next Greater Element I (LeetCode #496)
2. Next Greater Element II (LeetCode #503)
3. Next Greater Element III (LeetCode #556)
4. Online Stock Span (LeetCode #901)
5. Largest Rectangle in Histogram (LeetCode #84)
6. Maximal Rectangle (LeetCode #85)
7. Trapping Rain Water (LeetCode #42)
8. Sum of Subarray Minimums (LeetCode #907)
9. Remove K Digits (LeetCode #402)
10. Shortest Unsorted Continuous Subarray (LeetCode #581)
*/
