"""
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
"""



if __name__ == "__main__":
    sol = Solution()
    nums1 = [3, 10, 5, 25, 2, 8]
    print(f"Input: [3,10,5,25,2,8]")
    print(f"Output: {sol.findMaximumXOR(nums1)}")
    print(f"Explanation: 5 XOR 25 = 28")
    print(f"5:  00101")
    print(f"25: 11001")
    print(f"XOR:11100 = 28")
    nums2 = [14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70]
    print(f"Input: [14,70,53,83,49,91,36,80,92,51,66,70]")
    print(f"Output: {sol.findMaximumXOR(nums2)}")
    print(f"Explanation: Maximum XOR found = 127")
