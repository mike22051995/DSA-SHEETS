/*
================================================================================
PROBLEM: Lemonade Change (LeetCode #860)
DIFFICULTY: Easy
PATTERN: Greedy
COMPANIES: Amazon, Microsoft, Google
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        
        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else { // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> bills1 = {5,5,5,10,20};
    vector<int> bills2 = {5,5,10,10,20};
    
    cout << "Can provide change: " << (sol.lemonadeChange(bills1) ? "true" : "false") << endl;
    cout << "Can provide change: " << (sol.lemonadeChange(bills2) ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Best Time to Buy and Sell Stock (LeetCode #121)
2. Best Time to Buy and Sell Stock II (LeetCode #122)
3. Gas Station (LeetCode #134)
4. Jump Game (LeetCode #55)
5. Jump Game II (LeetCode #45)
6. Bag of Tokens (LeetCode #948)
7. Boats to Save People (LeetCode #881)
8. Maximum Units on Truck (LeetCode #1710)
9. Maximize Sum Of Array After K Negations (LeetCode #1005)
10. Minimum Cost to Move Chips (LeetCode #1217)
*/
