"""
PROBLEM: Lemonade Change (LeetCode 860)
DIFFICULTY: Easy
PATTERN: Greedy Simulation with State Tracking

DESCRIPTION:
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you 
and order one at a time (in the order specified by bills). Each customer will only buy one 
lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to 
each customer so that the net transaction is that the customer pays $5.
Return True if you can provide every customer with the correct change.

INPUT:
- bills: array of integers (5, 10, or 20) representing customer payments

OUTPUT:
- True if we can provide change to all customers, False otherwise

APPROACH:
1. Keep track of $5 and $10 bills (no need to track $20 as we never give it as change)
2. For each customer, check if we can provide change
3. Greedy choice: When giving change for $20, prefer using $10+$5 over three $5s
   (because $5 bills are more versatile)

WHY GREEDY WORKS:
$5 bills are the most useful, so we should preserve them when possible.
"""

from typing import List, Optional

class Solution:
    def lemonadeChange(self, bills):
        five = 0;  # Count of $5 bills
        ten = 0;   # Count of $10 bills
        for bill in bills:
            if bill == 5:
                five += 1  # Just collect the $5
            elif bill == 10:
                if five == 0:
                    return False  # Can't give change
                five -= 1
                ten += 1
            else: # bill == 20
                # Prefer giving 1 ten and 1 five over 3 fives
                if ten > 0 and five > 0:
                    ten -= 1
                    five -= 1
                elif five >= 3:
                    five -= 3
                else:
                    return False  # Can't give change
        return True


if __name__ == "__main__":
    sol = Solution()
    bills1 = [5, 5, 5, 10, 20]
    print(f"Test 1 - Bills: [5,5,5,10,20]")
    print(f"Output: {(sol.lemonadeChange(bills1)}")
    print(f"Expected: True")
    bills2 = [5, 5, 10, 10, 20]
    print(f"Test 2 - Bills: [5,5,10,10,20]")
    print(f"Output: {(sol.lemonadeChange(bills2)}")
    print(f"Expected: False")
    bills3 = [5, 5, 10]
    print(f"Test 3 - Bills: [5,5,10]")
    print(f"Output: {(sol.lemonadeChange(bills3)}")
    print(f"Expected: True")
