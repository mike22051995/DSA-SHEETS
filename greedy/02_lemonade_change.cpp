/*
PROBLEM: Lemonade Change (LeetCode 860)
DIFFICULTY: Easy
PATTERN: Greedy Simulation with State Tracking

DESCRIPTION:
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you 
and order one at a time (in the order specified by bills). Each customer will only buy one 
lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to 
each customer so that the net transaction is that the customer pays $5.
Return true if you can provide every customer with the correct change.

INPUT:
- bills: array of integers (5, 10, or 20) representing customer payments

OUTPUT:
- true if we can provide change to all customers, false otherwise

APPROACH:
1. Keep track of $5 and $10 bills (no need to track $20 as we never give it as change)
2. For each customer, check if we can provide change
3. Greedy choice: When giving change for $20, prefer using $10+$5 over three $5s
   (because $5 bills are more versatile)

WHY GREEDY WORKS:
$5 bills are the most useful, so we should preserve them when possible.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;  // Count of $5 bills
        int ten = 0;   // Count of $10 bills
        
        for (int bill : bills) {
            if (bill == 5) {
                five++; // Just collect the $5
            }
            else if (bill == 10) {
                if (five == 0) return false; // Can't give change
                five--;
                ten++;
            }
            else { // bill == 20
                // Prefer giving 1 ten and 1 five over 3 fives
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false; // Can't give change
                }
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> bills1 = {5, 5, 5, 10, 20};
    cout << "Test 1 - Bills: [5,5,5,10,20]" << endl;
    cout << "Output: " << (sol.lemonadeChange(bills1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Test Case 2
    vector<int> bills2 = {5, 5, 10, 10, 20};
    cout << "Test 2 - Bills: [5,5,10,10,20]" << endl;
    cout << "Output: " << (sol.lemonadeChange(bills2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;
    
    // Test Case 3
    vector<int> bills3 = {5, 5, 10};
    cout << "Test 3 - Bills: [5,5,10]" << endl;
    cout << "Output: " << (sol.lemonadeChange(bills3) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is the number of bills
SPACE COMPLEXITY: O(1) - only using two variables

KEY LEARNING:
- Greedy simulation: process events in order and make best local decision
- Track only necessary state (we don't need to track $20 bills)
- When multiple options exist, choose the one that preserves more flexibility
*/
