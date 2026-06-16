/*
PROBLEM: Baseball Game (LeetCode 682)
DIFFICULTY: Easy
PATTERN: Stack for Record Keeping

DESCRIPTION:
You're keeping score for a baseball game with operations:
- Integer x: Record a new score of x
- "+": Record sum of previous two scores
- "D": Record double of previous score
- "C": Invalidate previous score

Return the sum of all scores after all operations.

INPUT: ops = ["5","2","C","D","+"]
OUTPUT: 30
Explanation:
"5" - Add 5, total = [5]
"2" - Add 2, total = [5, 2]
"C" - Remove 2, total = [5]
"D" - Add 10 (2 * 5), total = [5, 10]
"+" - Add 15 (5 + 10), total = [5, 10, 15]
Sum = 5 + 10 + 15 = 30

TIME COMPLEXITY: O(n) where n is number of operations
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a stack to maintain valid scores. Process each operation:
- Number: push to stack
- "C": pop last score
- "D": push double of last score
- "+": push sum of last two scores
Finally, sum all elements in stack.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int calPoints(vector<string>& operations) {
    stack<int> scores;
    
    for (const string& op : operations) {
        if (op == "+") {
            // Sum of last two scores
            int top = scores.top();
            scores.pop();
            int newScore = top + scores.top();
            scores.push(top);  // Put back the popped value
            scores.push(newScore);
        } else if (op == "D") {
            // Double of last score
            scores.push(2 * scores.top());
        } else if (op == "C") {
            // Remove last score
            scores.pop();
        } else {
            // It's a number
            scores.push(stoi(op));
        }
    }
    
    // Calculate sum of all scores
    int sum = 0;
    while (!scores.empty()) {
        sum += scores.top();
        scores.pop();
    }
    
    return sum;
}

void printVector(const vector<string>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << "\"" << vec[i] << "\"";
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    vector<vector<string>> testCases = {
        {"5", "2", "C", "D", "+"},
        {"5", "-2", "4", "C", "D", "9", "+", "+"},
        {"1"},
        {"1", "C"},
        {"1", "2", "+", "D"}
    };
    
    for (const auto& ops : testCases) {
        cout << "Operations: ";
        printVector(ops);
        cout << endl;
        
        vector<string> opsCopy = ops;  // Make a copy since we modify it
        int result = calPoints(opsCopy);
        cout << "Total score: " << result << endl << endl;
    }
    
    return 0;
}
