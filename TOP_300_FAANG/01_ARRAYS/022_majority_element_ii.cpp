/*
================================================================================
PROBLEM: Majority Element II (LeetCode #229)
DIFFICULTY: Medium
PATTERN: Boyer-Moore Voting Algorithm
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;
        
        // Find potential candidates
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        // Verify candidates
        count1 = 0;
        count2 = 0;
        
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }
        
        vector<int> result;
        int n = nums.size();
        
        if (count1 > n / 3) result.push_back(candidate1);
        if (count2 > n / 3) result.push_back(candidate2);
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {3,2,3};
    vector<int> nums2 = {1,1,1,3,3,2,2,2};
    
    vector<int> result1 = sol.majorityElement(nums1);
    cout << "Majority elements (>n/3): ";
    for (int x : result1) cout << x << " ";
    cout << endl;
    
    vector<int> result2 = sol.majorityElement(nums2);
    cout << "Majority elements (>n/3): ";
    for (int x : result2) cout << x << " ";
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Majority Element (LeetCode #169)
2. Find All Duplicates in Array (LeetCode #442)
3. Find All Numbers Disappeared (LeetCode #448)
4. Single Number (LeetCode #136)
5. Single Number II (LeetCode #137)
6. Single Number III (LeetCode #260)
7. Top K Frequent Elements (LeetCode #347)
8. K-th Symbol in Grammar (LeetCode #779)
9. Most Frequent Subtree Sum (LeetCode #508)
10. Number of Boomerangs (LeetCode #447)
*/
