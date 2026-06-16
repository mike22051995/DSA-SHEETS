/*
PROBLEM: Asteroid Collision (LeetCode 735)
DIFFICULTY: Medium
PATTERN: Stack for Collision Detection

DESCRIPTION:
We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents 
its direction (positive = right, negative = left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions.

INPUT: asteroids = [5,10,-5]
OUTPUT: [5,10]
Explanation: 10 and -5 collide, -5 explodes. 5 and 10 never collide.

INPUT: asteroids = [8,-8]
OUTPUT: []
Explanation: 8 and -8 collide and both explode.

TIME COMPLEXITY: O(n) where n is the number of asteroids
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a stack to track surviving asteroids. When a right-moving asteroid meets a 
left-moving one, they collide. Compare sizes and destroy the smaller one.
Only right-moving asteroids can collide with future left-moving ones.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    
    for (int asteroid : asteroids) {
        bool alive = true;
        
        // Handle collision scenarios
        while (!st.empty() && asteroid < 0 && st.top() > 0) {
            // Collision happens
            if (st.top() < -asteroid) {
                // Top asteroid explodes, continue checking
                st.pop();
                continue;
            } else if (st.top() == -asteroid) {
                // Both explode
                st.pop();
            }
            // Current asteroid explodes
            alive = false;
            break;
        }
        
        if (alive) {
            st.push(asteroid);
        }
    }
    
    // Build result from stack
    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; i--) {
        result[i] = st.top();
        st.pop();
    }
    
    return result;
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
        {5, 10, -5},
        {8, -8},
        {10, 2, -5},
        {-2, -1, 1, 2},
        {1, -2, -2, -2}
    };
    
    for (auto& asteroids : testCases) {
        cout << "Asteroids: ";
        printVector(asteroids);
        cout << endl;
        
        vector<int> result = asteroidCollision(asteroids);
        cout << "After collision: ";
        printVector(result);
        cout << endl << endl;
    }
    
    return 0;
}
