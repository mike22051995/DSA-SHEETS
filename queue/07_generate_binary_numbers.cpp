/*
PROBLEM: Generate Binary Numbers from 1 to N
Difficulty: Easy
Pattern: Queue-based Generation

DESCRIPTION:
Given a number N, generate binary numbers from 1 to N using a queue.
The idea is to use queue to generate binary representation by appending 
0 and 1 to previous binary numbers.

INPUT:
N = 5

OUTPUT:
1 10 11 100 101

INPUT:
N = 10

OUTPUT:
1 10 11 100 101 110 111 1000 1001 1010

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// Generate binary numbers from 1 to n
vector<string> generateBinaryNumbers(int n) {
    vector<string> result;
    queue<string> q;
    
    // Start with "1"
    q.push("1");
    
    for (int i = 0; i < n; i++) {
        // Get front of queue
        string current = q.front();
        q.pop();
        
        // Add to result
        result.push_back(current);
        
        // Generate next two binary numbers
        // by appending "0" and "1"
        q.push(current + "0");
        q.push(current + "1");
    }
    
    return result;
}

// Alternative: Generate using bit manipulation (for comparison)
string decimalToBinary(int n) {
    if (n == 0) return "0";
    
    string binary = "";
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    return binary;
}

vector<string> generateBinaryNumbersAlt(int n) {
    vector<string> result;
    for (int i = 1; i <= n; i++) {
        result.push_back(decimalToBinary(i));
    }
    return result;
}

int main() {
    int n;
    
    cout << "Enter N: ";
    cin >> n;
    
    // Method 1: Using Queue
    cout << "\nMethod 1 (Queue): " << endl;
    vector<string> binary = generateBinaryNumbers(n);
    for (const string& num : binary) {
        cout << num << " ";
    }
    cout << endl;
    
    // Method 2: Using Bit Manipulation
    cout << "\nMethod 2 (Bit Manipulation): " << endl;
    vector<string> binaryAlt = generateBinaryNumbersAlt(n);
    for (const string& num : binaryAlt) {
        cout << num << " ";
    }
    cout << endl;
    
    // Test cases
    cout << "\n=== Test Cases ===" << endl;
    for (int test : {3, 8, 12}) {
        cout << "N = " << test << ": ";
        vector<string> res = generateBinaryNumbers(test);
        for (const string& num : res) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
EXPLANATION:

Queue-based approach:
1. Start with "1" in queue
2. For each iteration:
   - Dequeue front element
   - Add it to result
   - Generate two new numbers by appending "0" and "1"
   - Enqueue both new numbers
3. This creates a tree-like generation:
   1
   ├─ 10
   │  ├─ 100
   │  └─ 101
   └─ 11
      ├─ 110
      └─ 111

PATTERN FLOW:
1 -> {10, 11}
10 -> {100, 101}
11 -> {110, 111}
100 -> {1000, 1001}
...

KEY LEARNING POINTS:
- Queue generates level-by-level (BFS pattern)
- Each number generates two children
- More elegant than bit manipulation for this specific problem
- Common in Microsoft, Amazon interviews
- Demonstrates queue's application beyond basic operations
*/
