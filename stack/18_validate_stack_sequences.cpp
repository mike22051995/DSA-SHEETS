/*
PROBLEM: Validate Stack Sequences (LeetCode 946)
DIFFICULTY: Medium
PATTERN: Stack Simulation

DESCRIPTION:
Given two integer arrays pushed and popped each with distinct values, 
return true if this could have been the result of a sequence of push and pop 
operations on an initially empty stack, or false otherwise.

INPUT: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
OUTPUT: true
Explanation: push(1), push(2), push(3), push(4), pop() -> 4, push(5), pop() -> 5, 
pop() -> 3, pop() -> 2, pop() -> 1

INPUT: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
OUTPUT: false

TIME COMPLEXITY: O(n) where n is the length of arrays
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Simulate the stack operations. For each element in pushed, push to stack.
After each push, try to pop elements that match the current position in popped array.
If all elements can be popped successfully, return true.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int j = 0;  // Index for popped array
    
    for (int num : pushed) {
        st.push(num);
        
        // Try to pop elements matching popped sequence
        while (!st.empty() && st.top() == popped[j]) {
            st.pop();
            j++;
        }
    }
    
    // All elements should be popped
    return st.empty();
}

void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    vector<pair<vector<int>, vector<int>>> testCases = {
        {{1, 2, 3, 4, 5}, {4, 5, 3, 2, 1}},
        {{1, 2, 3, 4, 5}, {4, 3, 5, 1, 2}},
        {{1, 2, 3}, {3, 2, 1}},
        {{1, 2, 3}, {1, 2, 3}},
        {{2, 1, 0}, {1, 2, 0}}
    };
    
    for (auto& test : testCases) {
        vector<int> pushed = test.first;
        vector<int> popped = test.second;
        
        cout << "Pushed: ";
        printVector(pushed);
        cout << endl;
        cout << "Popped: ";
        printVector(popped);
        cout << endl;
        
        bool result = validateStackSequences(pushed, popped);
        cout << "Valid: " << (result ? "true" : "false") << endl << endl;
    }
    
    return 0;
}
