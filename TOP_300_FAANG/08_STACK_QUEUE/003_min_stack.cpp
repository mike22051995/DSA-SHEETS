/*
================================================================================
PROBLEM: Min Stack (LeetCode #155)
DIFFICULTY: Medium
PATTERN: Stack with Tracking
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple, Bloomberg
================================================================================
*/

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;
    
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

// Alternative: Single Stack with min tracking
class MinStack2 {
private:
    stack<pair<int, int>> st; // {value, min_so_far}
    
public:
    MinStack2() {}
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            st.push({val, min(val, st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Min: " << minStack.getMin() << endl;  // -3
    minStack.pop();
    cout << "Top: " << minStack.top() << endl;     // 0
    cout << "Min: " << minStack.getMin() << endl;  // -2
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Max Stack (LeetCode #716)
2. Min Stack II (Follow-up questions)
3. Sliding Window Maximum (LeetCode #239)
4. Design a Stack With Increment (LeetCode #1381)
5. Implement Queue using Stacks (LeetCode #232)
6. Implement Stack using Queues (LeetCode #225)
7. Design Circular Queue (LeetCode #622)
8. Design Front Middle Back Queue (LeetCode #1670)
9. LRU Cache (LeetCode #146)
10. LFU Cache (LeetCode #460)
*/
