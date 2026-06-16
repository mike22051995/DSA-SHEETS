/*
PROBLEM: Minimum Cost to Connect Sticks (LeetCode 1167)
DIFFICULTY: Medium
PATTERN: Greedy Huffman Coding / Merge Smallest First

DESCRIPTION:
You have some sticks with positive integer lengths. You can connect any two sticks of 
lengths X and Y into one stick by paying a cost of X + Y. Perform this until one stick 
remains. Return the minimum cost of connecting all sticks.

INPUT:
- sticks: array of positive integers

OUTPUT:
- Minimum cost to connect all sticks

APPROACH:
1. Use a min heap (priority queue)
2. Always connect two smallest sticks
3. Add the combined stick back to heap
4. Continue until one stick remains

WHY GREEDY WORKS:
Smaller sticks should be combined first because they'll be counted multiple times.
This is similar to Huffman encoding - minimize weighted path length.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        // Min heap to always get two smallest sticks
        priority_queue<int, vector<int>, greater<int>> minHeap(sticks.begin(), sticks.end());
        
        int totalCost = 0;
        
        // Keep combining until one stick remains
        while (minHeap.size() > 1) {
            // Take two smallest sticks
            int first = minHeap.top();
            minHeap.pop();
            int second = minHeap.top();
            minHeap.pop();
            
            // Cost to combine them
            int cost = first + second;
            totalCost += cost;
            
            // Put combined stick back
            minHeap.push(cost);
        }
        
        return totalCost;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> sticks1 = {2, 4, 3};
    cout << "Test 1 - Sticks: [2,4,3]" << endl;
    cout << "Output: " << sol.connectSticks(sticks1) << endl;
    cout << "Expected: 14 (connect 2+3=5 cost 5, then 5+4=9 cost 9, total 14)" << endl << endl;
    
    // Test Case 2
    vector<int> sticks2 = {1, 8, 3, 5};
    cout << "Test 2 - Sticks: [1,8,3,5]" << endl;
    cout << "Output: " << sol.connectSticks(sticks2) << endl;
    cout << "Expected: 30" << endl << endl;
    
    // Test Case 3
    vector<int> sticks3 = {5};
    cout << "Test 3 - Sticks: [5]" << endl;
    cout << "Output: " << sol.connectSticks(sticks3) << endl;
    cout << "Expected: 0 (only one stick)" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n log n) where n is number of sticks
SPACE COMPLEXITY: O(n) for the heap

KEY LEARNING:
- Greedy with heap: always pick smallest elements
- Similar to Huffman coding algorithm
- Merge smallest first to minimize total cost
- Pattern appears in: merge files, combine operations
- Priority queue is essential for greedy algorithms
- Common in Amazon/Google interviews
*/
