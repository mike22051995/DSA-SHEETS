/*
PROBLEM: Book Allocation Problem
Difficulty: Hard
Pattern: Binary Search on Answer

DESCRIPTION:
Given an array of N books where ith book has pages[i] pages. M students need to be allocated 
contiguous books, with each student getting at least one book. Allocate books such that the 
maximum number of pages allocated to a student is minimized.

EXPLANATION:
Binary search on maximum pages:
- Min pages = max(pages) (student must read largest book)
- Max pages = sum(pages) (one student reads all)
- For each mid, check if M students can be allocated
- Find minimum maximum pages

Time Complexity: O(n * log(sum))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: pages = [12,34,67,90], students = 2
Output: 113
Explanation: Student 1: [12,34,67], Student 2: [90]

Example 2:
Input: pages = [10,20,30,40], students = 2
Output: 60
Explanation: Student 1: [10,20,30], Student 2: [40]

Example 3:
Input: pages = [5,17,100,11], students = 4
Output: 100
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int allocateBooks(vector<int>& pages, int students) {
        if (students > pages.size()) return -1;
        
        int left = *max_element(pages.begin(), pages.end());
        int right = accumulate(pages.begin(), pages.end(), 0);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canAllocate(pages, students, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canAllocate(vector<int>& pages, int students, int maxPages) {
        int studentsNeeded = 1;
        int currentPages = 0;
        
        for (int page : pages) {
            if (currentPages + page > maxPages) {
                studentsNeeded++;
                currentPages = page;
                
                if (studentsNeeded > students) {
                    return false;
                }
            } else {
                currentPages += page;
            }
        }
        
        return true;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> pages1 = {12,34,67,90};
    cout << "Test 1: " << solution.allocateBooks(pages1, 2) << endl;
    
    // Test Case 2
    vector<int> pages2 = {10,20,30,40};
    cout << "Test 2: " << solution.allocateBooks(pages2, 2) << endl;
    
    // Test Case 3
    vector<int> pages3 = {5,17,100,11};
    cout << "Test 3: " << solution.allocateBooks(pages3, 4) << endl;
    
    return 0;
}
