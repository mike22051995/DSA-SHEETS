/*
PROBLEM: Maximum XOR of Two Numbers in Array
==============================================
Find the maximum XOR of two numbers in an array.

APPROACH:
- Use Trie (prefix tree) to store binary representation
- For each number, try to find its complement that maximizes XOR
- At each bit, prefer opposite bit for maximum XOR

PATTERN: Trie with Bit Manipulation - XOR Maximization

INPUT/OUTPUT:
Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: Maximum XOR is 5 XOR 25 = 28

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127

TIME COMPLEXITY: O(n * 32) - n numbers, 32 bits each
SPACE COMPLEXITY: O(n * 32) - Trie storage
*/

#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode* children[2]; // 0 and 1
    
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Solution {
private:
    TrieNode* root;
    
    void insert(int num) {
        TrieNode* node = root;
        // Process from MSB to LSB (31 to 0)
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }
    
    int findMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            // Try to go opposite direction for max XOR
            int oppositeBit = 1 - bit;
            
            if (node->children[oppositeBit] != nullptr) {
                maxXOR |= (1 << i);
                node = node->children[oppositeBit];
            } else {
                node = node->children[bit];
            }
        }
        
        return maxXOR;
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        
        // Insert all numbers into Trie
        for (int num : nums) {
            insert(num);
        }
        
        // Find maximum XOR for each number
        int maxResult = 0;
        for (int num : nums) {
            maxResult = max(maxResult, findMaxXOR(num));
        }
        
        return maxResult;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {3, 10, 5, 25, 2, 8};
    cout << "Input: [3,10,5,25,2,8]" << endl;
    cout << "Output: " << sol.findMaximumXOR(nums1) << endl;
    cout << "Explanation: 5 XOR 25 = 28" << endl;
    cout << "5:  00101" << endl;
    cout << "25: 11001" << endl;
    cout << "XOR:11100 = 28" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    cout << "Input: [14,70,53,83,49,91,36,80,92,51,66,70]" << endl;
    cout << "Output: " << sol.findMaximumXOR(nums2) << endl;
    cout << "Explanation: Maximum XOR found = 127" << endl;
    
    return 0;
}
