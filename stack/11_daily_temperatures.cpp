/*
PROBLEM: Daily Temperatures (LeetCode 739)
DIFFICULTY: Medium
PATTERN: Monotonic Stack

DESCRIPTION:
Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to 
wait after the ith day to get a warmer temperature. If there is no future day 
for which this is possible, keep answer[i] == 0.

INPUT: temperatures = [73,74,75,71,69,72,76,73]
OUTPUT: [1,1,4,2,1,1,0,0]
Explanation: Day 0: Next warmer is day 1 (1 day), Day 2: Next warmer is day 6 (4 days)

TIME COMPLEXITY: O(n) where n is the number of days
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a monotonic decreasing stack to store indices of temperatures.
For each day, pop all indices with lower temperatures and calculate the difference.
The stack maintains indices of temperatures in decreasing order, allowing us to
find the next warmer day efficiently.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> st;  // Store indices
    
    for (int i = 0; i < n; i++) {
        // While current temp is warmer than stack top's temp
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int prevIndex = st.top();
            st.pop();
            answer[prevIndex] = i - prevIndex;
        }
        st.push(i);
    }
    
    return answer;
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
    vector<vector<int>> testCases = {
        {73, 74, 75, 71, 69, 72, 76, 73},
        {30, 40, 50, 60},
        {30, 60, 90},
        {89, 62, 70, 58, 47, 47, 46, 76, 100, 70}
    };
    
    for (auto& temps : testCases) {
        cout << "Temperatures: ";
        printVector(temps);
        cout << endl;
        
        vector<int> result = dailyTemperatures(temps);
        cout << "Days to wait: ";
        printVector(result);
        cout << endl << endl;
    }
    
    return 0;
}
