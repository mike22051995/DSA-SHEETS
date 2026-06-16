/*
================================================================================
PROBLEM: Sort Colors (Dutch National Flag) (LeetCode #75)
DIFFICULTY: Medium
PATTERN: Three Pointers / Partition
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
    
    // Two pass - counting sort
    void sortColorsCounting(vector<int>& nums) {
        int count[3] = {0};
        
        for (int num : nums) {
            count[num]++;
        }
        
        int index = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < count[i]; j++) {
                nums[index++] = i;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,0,2,1,1,0};
    sol.sortColors(nums);
    
    cout << "Sorted colors: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Sort Array By Parity (LeetCode #905)
2. Sort Array By Parity II (LeetCode #922)
3. Move Zeroes (LeetCode #283)
4. Partition Array (LeetCode #2161)
5. Partition Labels (LeetCode #763)
6. Quick Sort Implementation
7. Three Way Partitioning
8. Separate Black and White Balls (LeetCode #2938)
9. Sort Transformed Array (LeetCode #360)
10. Wiggle Sort (LeetCode #280)
*/
