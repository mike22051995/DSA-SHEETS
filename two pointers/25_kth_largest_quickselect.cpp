/*
PROBLEM: Kth Largest Element (QuickSelect Partition)
---------------------------------------------------------------------------
Find the kth largest element in an unsorted array. Note that it is the 
kth largest element in sorted order, not the kth distinct element.

PATTERN: Two Pointers (QuickSelect - Partition)
TIME COMPLEXITY: O(n) average, O(n²) worst case
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Explanation: When sorted: [1,2,3,4,5,6]. 2nd largest is 5.

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
Explanation: When sorted: [1,2,2,3,3,4,5,5,6]. 4th largest is 4.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        int left = 0;
        int right = nums.size() - 1;
        int target = nums.size() - k; // Convert to kth smallest
        
        while (left <= right) {
            int pivotIndex = partition(nums, left, right);
            
            if (pivotIndex == target) {
                return nums[pivotIndex];
            } else if (pivotIndex < target) {
                left = pivotIndex + 1;
            } else {
                right = pivotIndex - 1;
            }
        }
        
        return -1;
    }
    
private:
    int partition(vector<int>& nums, int left, int right) {
        // Random pivot for better average performance
        int randomIndex = left + rand() % (right - left + 1);
        swap(nums[randomIndex], nums[right]);
        
        int pivot = nums[right];
        int i = left;
        
        for (int j = left; j < right; j++) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        
        swap(nums[i], nums[right]);
        return i;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    cout << "Test 1: " << sol.findKthLargest(nums1, k1) << endl;
    
    // Test case 2
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << "Test 2: " << sol.findKthLargest(nums2, k2) << endl;
    
    return 0;
}
