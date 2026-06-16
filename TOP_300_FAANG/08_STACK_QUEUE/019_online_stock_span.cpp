/*
================================================================================
PROBLEM: Online Stock Span (LeetCode #901)
DIFFICULTY: Medium
PATTERN: Monotonic Stack
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================

PROBLEM DESCRIPTION:
Design an algorithm that collects daily price quotes for some stock and returns
the span of that stock's price for the current day. The span of the stock's
price in one day is the maximum number of consecutive days (starting from that
day and going backward) for which the stock price was less than or equal to
the price of that day.

EXAMPLES:

Example 1:
Input:
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output:
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation:
Day 1: price=100, span=1
Day 2: price=80, span=1 (80 < 100)
Day 3: price=60, span=1 (60 < 80)
Day 4: price=70, span=2 (70 >= 60, 70 < 80)
Day 5: price=60, span=1 (60 < 70)
Day 6: price=75, span=4 (75 >= 60, 70, 60, 75 < 80)
Day 7: price=85, span=6 (85 >= all previous)

PATTERN RECOGNITION:
Use this pattern when:
- Need to find previous greater/smaller elements
- Monotonic stack for efficient lookback
- Track position/index with values
*/

#include <iostream>
#include <stack>
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> stk;  // {price, span}
    
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        
        while (!stk.empty() && stk.top().first <= price) {
            span += stk.top().second;
            stk.pop();
        }
        
        stk.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner spanner;
    
    cout << "next(100): " << spanner.next(100) << endl;
    cout << "next(80): " << spanner.next(80) << endl;
    cout << "next(60): " << spanner.next(60) << endl;
    cout << "next(70): " << spanner.next(70) << endl;
    cout << "next(60): " << spanner.next(60) << endl;
    cout << "next(75): " << spanner.next(75) << endl;
    cout << "next(85): " << spanner.next(85) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: Amortized O(1) per call
SPACE COMPLEXITY: O(n) for stack

SIMILAR PROBLEMS:
1. Daily Temperatures (LeetCode #739)
2. Next Greater Element I (LeetCode #496)
3. Next Greater Element II (LeetCode #503)
4. Largest Rectangle in Histogram (LeetCode #84)
5. Maximal Rectangle (LeetCode #85)
6. Trapping Rain Water (LeetCode #42)
7. Remove K Digits (LeetCode #402)
8. Maximum Width Ramp (LeetCode #962)
9. Sum of Subarray Minimums (LeetCode #907)
10. Minimum Cost Tree From Leaf Values (LeetCode #1130)
*/
