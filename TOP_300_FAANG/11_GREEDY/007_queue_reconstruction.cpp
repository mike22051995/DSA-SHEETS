/*
================================================================================
PROBLEM: Queue Reconstruction by Height (LeetCode #406)
DIFFICULTY: Medium
PATTERN: Greedy / Sorting
COMPANIES: Amazon, Facebook, Google, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort by height descending, then by k ascending
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        
        vector<vector<int>> result;
        
        for (auto& person : people) {
            result.insert(result.begin() + person[1], person);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    
    vector<vector<int>> result = sol.reconstructQueue(people);
    
    cout << "Reconstructed queue:" << endl;
    for (auto& person : result) {
        cout << "[" << person[0] << "," << person[1] << "] ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Count of Smaller Numbers After Self (LeetCode #315)
2. Count of Range Sum (LeetCode #327)
3. Russian Doll Envelopes (LeetCode #354)
4. Maximum Height by Stacking Cuboids (LeetCode #1691)
5. Relative Sort Array (LeetCode #1122)
6. Sort Array By Parity (LeetCode #905)
7. Sort Colors (LeetCode #75)
8. Wiggle Sort II (LeetCode #324)
9. Advantage Shuffle (LeetCode #870)
10. Car Fleet (LeetCode #853)
*/
