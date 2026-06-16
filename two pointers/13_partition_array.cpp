/*
PROBLEM: Partition Array According to Given Pivot (LeetCode 2161)
---------------------------------------------------------------------------
Given a 0-indexed integer array nums and an integer pivot, rearrange nums 
such that:
- All elements less than pivot appear before elements greater than pivot
- All elements equal to pivot appear in between
- Relative order of elements less/greater than pivot is maintained

PATTERN: Three Pointers / Dutch National Flag Variation
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) for stable, O(1) for in-place unstable

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]
Explanation: Elements < 10 are [9,5,3], equal are [10,10], greater are [12,14]

Example 2:
Input: nums = [-3,4,3,2], pivot = 2
Output: [-3,2,4,3]
Explanation: Elements < 2 is [-3], equal is [2], greater are [4,3]

KEY INSIGHT:
- If relative order MUST be maintained: Need O(n) space (3-pass or counting)
- If relative order doesn't matter: Can use Dutch National Flag O(1) space
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Approach 1: Three-Pass with Extra Space (Maintains Relative Order)
    // TIME: O(n), SPACE: O(n)
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;
        
        // First pass: add all elements less than pivot
        for (int num : nums) {
            if (num < pivot) {
                result.push_back(num);
            }
        }
        
        // Second pass: add all elements equal to pivot
        for (int num : nums) {
            if (num == pivot) {
                result.push_back(num);
            }
        }
        
        // Third pass: add all elements greater than pivot
        for (int num : nums) {
            if (num > pivot) {
                result.push_back(num);
            }
        }
        
        return result;
    }
    
    // Approach 2: One-Pass with Counting (Still O(n) space but cleaner)
    // TIME: O(n), SPACE: O(n)
    vector<int> pivotArrayCounting(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;
        
        for (int num : nums) {
            if (num < pivot) {
                less.push_back(num);
            } else if (num == pivot) {
                equal.push_back(num);
            } else {
                greater.push_back(num);
            }
        }
        
        // Combine all three vectors
        less.insert(less.end(), equal.begin(), equal.end());
        less.insert(less.end(), greater.begin(), greater.end());
        
        return less;
    }
    
    // Approach 3: Dutch National Flag - In-Place Three Pointers
    // TIME: O(n), SPACE: O(1)
    // WARNING: Does NOT maintain relative order!
    void pivotArrayInPlace(vector<int>& nums, int pivot) {
        int n = nums.size();
        int left = 0;      // Pointer for elements < pivot
        int mid = 0;       // Current pointer scanning array
        int right = n - 1; // Pointer for elements > pivot
        
        // Similar to Dutch National Flag (Sort Colors)
        while (mid <= right) {
            if (nums[mid] < pivot) {
                // Element < pivot: swap to left section
                swap(nums[left], nums[mid]);
                left++;
                mid++;
            } 
            else if (nums[mid] > pivot) {
                // Element > pivot: swap to right section
                swap(nums[mid], nums[right]);
                right--;
                // Don't increment mid! Need to check swapped element
            } 
            else {
                // Element == pivot: already in correct position
                mid++;
            }
        }
        
        // Result: [< pivot ... | == pivot ... | > pivot ...]
        //         [0...left-1] [left...right] [right+1...n-1]
    }
    
    // Approach 4: YOUR IDEA - Three Pointers with Write Positions
    // TIME: O(n), SPACE: O(n) for result array
    // This maintains relative order!
    vector<int> pivotArrayThreePointers(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);
        
        int less = 0;      // Write position for elements < pivot
        int equal = 0;     // Write position for elements == pivot (calculated)
        int greater = 0;   // Write position for elements > pivot
        
        // First pass: count elements in each category
        int countLess = 0, countEqual = 0, countGreater = 0;
        for (int num : nums) {
            if (num < pivot) countLess++;
            else if (num == pivot) countEqual++;
            else countGreater++;
        }
        
        // Set write positions
        less = 0;
        equal = countLess;
        greater = countLess + countEqual;
        
        // Second pass: place elements at correct positions
        for (int num : nums) {
            if (num < pivot) {
                result[less++] = num;
            } 
            else if (num == pivot) {
                result[equal++] = num;
            } 
            else {
                result[greater++] = num;
            }
        }
        
        return result;
    }
    
    // Approach 5: True O(1) Space In-Place (Cycle Sort Variant)
    // TIME: O(n²) worst case, SPACE: O(1)
    // Maintains relative order but slower
    void pivotArrayStableInPlace(vector<int>& nums, int pivot) {
        int n = nums.size();
        
        // Move all elements < pivot to the front (stable)
        int writePos = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                int temp = nums[i];
                // Shift elements right to make space
                for (int j = i; j > writePos; j--) {
                    nums[j] = nums[j-1];
                }
                nums[writePos] = temp;
                writePos++;
            }
        }
        
        // Move all elements > pivot to the end (stable)
        writePos = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > pivot) {
                int temp = nums[i];
                // Shift elements left to make space
                for (int j = i; j < writePos; j++) {
                    nums[j] = nums[j+1];
                }
                nums[writePos] = temp;
                writePos--;
            }
        }
    }
};

int main() {
    Solution sol;
    
    cout << "=== APPROACH 1: Three-Pass (Stable, O(n) space) ===" << endl;
    vector<int> nums1 = {9, 12, 5, 10, 14, 3, 10};
    int pivot1 = 10;
    vector<int> result1 = sol.pivotArray(nums1, pivot1);
    cout << "Input:  [9,12,5,10,14,3,10], pivot=10" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i] << (i < result1.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    cout << "\n=== APPROACH 2: Counting (Stable, O(n) space) ===" << endl;
    vector<int> nums2 = {-3, 4, 3, 2};
    int pivot2 = 2;
    vector<int> result2 = sol.pivotArrayCounting(nums2, pivot2);
    cout << "Input:  [-3,4,3,2], pivot=2" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << (i < result2.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    cout << "\n=== APPROACH 3: Dutch National Flag (UNSTABLE, O(1) space) ===" << endl;
    vector<int> nums3 = {9, 12, 5, 10, 14, 3, 10};
    int pivot3 = 10;
    cout << "Input:  [9,12,5,10,14,3,10], pivot=10" << endl;
    sol.pivotArrayInPlace(nums3, pivot3);
    cout << "Output: [";
    for (int i = 0; i < nums3.size(); i++) {
        cout << nums3[i] << (i < nums3.size() - 1 ? "," : "");
    }
    cout << "] (Relative order NOT maintained!)" << endl;
    
    cout << "\n=== APPROACH 4: YOUR IDEA - Three Write Pointers (Stable, O(n) space) ===" << endl;
    vector<int> nums4 = {9, 12, 5, 10, 14, 3, 10};
    int pivot4 = 10;
    vector<int> result4 = sol.pivotArrayThreePointers(nums4, pivot4);
    cout << "Input:  [9,12,5,10,14,3,10], pivot=10" << endl;
    cout << "Output: [";
    for (int i = 0; i < result4.size(); i++) {
        cout << result4[i] << (i < result4.size() - 1 ? "," : "");
    }
    cout << "] (Two passes: count + place)" << endl;
    
    cout << "\n=== APPROACH 5: Stable In-Place (Stable, O(1) space, O(n²) time) ===" << endl;
    vector<int> nums5 = {9, 12, 5, 10, 14, 3, 10};
    int pivot5 = 10;
    cout << "Input:  [9,12,5,10,14,3,10], pivot=10" << endl;
    sol.pivotArrayStableInPlace(nums5, pivot5);
    cout << "Output: [";
    for (int i = 0; i < nums5.size(); i++) {
        cout << nums5[i] << (i < nums5.size() - 1 ? "," : "");
    }
    cout << "] (Slower but truly in-place!)" << endl;
    
    cout << "\n=== COMPARISON ===" << endl;
    cout << "Approach 1 (Three-Pass):      O(n) time, O(n) space, Stable ✓" << endl;
    cout << "Approach 2 (Counting):        O(n) time, O(n) space, Stable ✓" << endl;
    cout << "Approach 3 (Dutch Flag):      O(n) time, O(1) space, UNSTABLE ✗" << endl;
    cout << "Approach 4 (Your Idea):       O(n) time, O(n) space, Stable ✓" << endl;
    cout << "Approach 5 (Stable In-Place): O(n²) time, O(1) space, Stable ✓" << endl;
    
    return 0;
}

/*
DETAILED EXPLANATION:

YOUR IDEA (Approach 4) - Three Write Pointers:
===============================================
This is BRILLIANT for understanding! You use three pointers to track WHERE to write:
- less pointer: writes elements < pivot
- equal pointer: writes elements == pivot
- greater pointer: writes elements > pivot

Algorithm:
1. Count how many elements in each category
2. Calculate starting positions:
   - less starts at 0
   - equal starts at countLess
   - greater starts at countLess + countEqual
3. Scan array again and place each element at correct position

Example: [9,12,5,10,14,3,10], pivot=10
Count: less=3, equal=2, greater=2
Positions: less=0, equal=3, greater=5

Pass through:
- 9 < 10 → result[0]=9, less++
- 12 > 10 → result[5]=12, greater++
- 5 < 10 → result[1]=5, less++
- 10 == 10 → result[3]=10, equal++
- 14 > 10 → result[6]=14, greater++
- 3 < 10 → result[2]=3, less++
- 10 == 10 → result[4]=10, equal++

Result: [9,5,3,10,10,12,14] ✓

WHY NOT TRUE O(1) SPACE?
=========================
Your idea still needs O(n) space for result array because we're placing
elements at calculated positions. To be truly O(1), we'd need to move 
elements IN THE ORIGINAL array.

COMPARISON OF SPACE-OPTIMIZED APPROACHES:

1. Dutch National Flag (Approach 3):
   - O(1) space but DESTROYS relative order
   - Great for "Sort Colors" but not this problem
   - Example: [9,12,5,10,14,3,10] might become [3,5,9,10,10,14,12]
   
2. Stable In-Place (Approach 5):
   - O(1) space and MAINTAINS relative order
   - But O(n²) time due to shifting elements
   - Trade-off: space for time

THE FUNDAMENTAL TRADE-OFF:
===========================
For this specific problem with stability requirement:
- FAST + STABLE = Need O(n) space ← Usually best choice
- SLOW + STABLE = Can do O(1) space but O(n²) time
- FAST + O(1) space = Cannot maintain stability

This is why LeetCode solution uses O(n) space!

WHEN TO USE WHICH:
==================
- Interview: Use Approach 1 or 4 (O(n) space, stable, fast)
- Follow-up "Can we do better space?": Explain trade-off
- If stability not required: Use Dutch National Flag
- If array is small and space critical: Use Approach 5

YOUR APPROACH IS EXCELLENT FOR:
================================
1. Understanding the problem structure
2. Explaining the algorithm clearly
3. Easy to code and understand
4. Similar pattern to Quick Sort partitioning
5. Foundation for understanding other partition algorithms

PATTERN CONNECTION:
===================
This three-pointer idea appears in:
- Quicksort partitioning
- Dutch National Flag
- Sort Colors
- Move Zeroes
- Segregate Even-Odd

Keep thinking like this - it's exactly the right intuition! 🎯
*/
