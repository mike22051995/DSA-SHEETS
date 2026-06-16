#include <iostream>
#include <stack>
#include <vector>
/*
PROBLEM: Online Stock Span (LeetCode 901)
DIFFICULTY: Medium
PATTERN: Monotonic Stack for Stock Span

DESCRIPTION:
Design an algorithm that collects daily price quotes for some stock and returns 
the span of that stock's price for the current day.
The span of the stock's price today is defined as the maximum number of consecutive 
days (starting from today and going backward) for which the stock price was less than 
or equal to today's price.

INPUT: 
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4
stockSpanner.next(85);  // return 6

TIME COMPLEXITY: O(1) amortized for next()
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a monotonic decreasing stack storing pairs of (price, span).
For each new price, pop all smaller or equal prices and accumulate their spans.
This gives us the span for current price efficiently.
*/

#include <iostream>
#include <stack>
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> st;  // {price, span}

public:
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        
        // Pop all prices less than or equal to current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        st.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner stockSpanner;
    
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    
    cout << "Price -> Span" << endl;
    cout << "-------------" << endl;
    
    for (int price : prices) {
        int span = stockSpanner.next(price);
        cout << price << " -> " << span << endl;
    }
    
    cout << "\nAnother example:" << endl;
    StockSpanner stockSpanner2;
    vector<int> prices2 = {31, 41, 48, 59, 79};
    
    cout << "Price -> Span" << endl;
    cout << "-------------" << endl;
    
    for (int price : prices2) {
        int span = stockSpanner2.next(price);
        cout << price << " -> " << span << endl;
    }
    
    return 0;
}
