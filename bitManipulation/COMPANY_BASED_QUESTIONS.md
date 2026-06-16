# Company-Based Bit Manipulation Interview Questions 🏢

## Table of Contents
- [Google](#google)
- [Meta/Facebook](#metafacebook)
- [Amazon](#amazon)
- [Microsoft](#microsoft)
- [Apple](#apple)
- [Netflix](#netflix)
- [Additional Companies](#additional-companies)

---

## Google

### 1. Single Number (Easy)
**Question:** Given a non-empty array of integers where every element appears twice except for one, find that single one. You must implement a solution with O(1) space complexity.

**Solution:**
```cpp
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}
```
**Time:** O(n) | **Space:** O(1)

**Explanation:** XOR has property: a ^ a = 0 and a ^ 0 = a. All pairs cancel out.

---

### 2. Maximum XOR of Two Numbers in Array (Medium)
**Question:** Given an integer array nums, find the maximum result of nums[i] XOR nums[j], where 0 ≤ i, j < nums.length.

**Solution:**
```cpp
class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() { children[0] = children[1] = nullptr; }
};

class Solution {
    TrieNode* root;
    
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }
    
    int findMax(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppBit = 1 - bit;
            if (node->children[oppBit]) {
                maxXOR |= (1 << i);
                node = node->children[oppBit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXOR;
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        for (int num : nums) insert(num);
        
        int maxResult = 0;
        for (int num : nums) {
            maxResult = max(maxResult, findMax(num));
        }
        return maxResult;
    }
};
```
**Time:** O(n * 32) | **Space:** O(n * 32)

**Key Insight:** Use Trie to store binary representations. For each number, traverse Trie choosing opposite bits to maximize XOR.

---

### 3. Counting Bits (Medium)
**Question:** Given an integer n, return an array ans of length n + 1 such that for each i (0 ≤ i ≤ n), ans[i] is the number of 1's in the binary representation of i.

**Solution:**
```cpp
vector<int> countBits(int n) {
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i >> 1] + (i & 1);
    }
    return ans;
}
```
**Time:** O(n) | **Space:** O(n)

**DP Relation:** `bits[i] = bits[i/2] + (i % 2)`

---

### 4. Single Number III (Medium)
**Question:** Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice, find the two elements that appear only once.

**Solution:**
```cpp
vector<int> singleNumber(vector<int>& nums) {
    int xorAll = 0;
    for (int num : nums) xorAll ^= num;
    
    // Find rightmost set bit (differentiating bit)
    int rightBit = xorAll & (-xorAll);
    
    int num1 = 0, num2 = 0;
    for (int num : nums) {
        if (num & rightBit) {
            num1 ^= num;
        } else {
            num2 ^= num;
        }
    }
    return {num1, num2};
}
```
**Time:** O(n) | **Space:** O(1)

**Key Insight:** Partition array based on a bit that differs between the two unique numbers.

---

### 5. Gray Code (Medium)
**Question:** An n-bit gray code sequence is a sequence of 2^n integers where two successive values differ in only one bit.

**Solution:**
```cpp
vector<int> grayCode(int n) {
    vector<int> result;
    int size = 1 << n;
    for (int i = 0; i < size; i++) {
        result.push_back(i ^ (i >> 1));
    }
    return result;
}
```
**Time:** O(2^n) | **Space:** O(2^n)

**Formula:** `gray(i) = i ^ (i >> 1)`

---

## Meta/Facebook

### 1. Missing Number (Easy)
**Question:** Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

**Solution:**
```cpp
int missingNumber(vector<int>& nums) {
    int result = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        result ^= i ^ nums[i];
    }
    return result;
}
```
**Time:** O(n) | **Space:** O(1)

**Alternative:** Sum formula: `n*(n+1)/2 - sum(array)`

---

### 2. Power of Two (Easy)
**Question:** Given an integer n, return true if it is a power of two. Otherwise, return false.

**Solution:**
```cpp
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```
**Time:** O(1) | **Space:** O(1)

**Key:** Power of 2 has exactly one set bit. `n & (n-1)` clears rightmost bit.

---

### 3. Subsets (Medium)
**Question:** Given an integer array nums of unique elements, return all possible subsets (the power set).

**Solution:**
```cpp
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    int totalSubsets = 1 << n;  // 2^n
    
    for (int mask = 0; mask < totalSubsets; mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        result.push_back(subset);
    }
    return result;
}
```
**Time:** O(n * 2^n) | **Space:** O(n * 2^n)

**Key Insight:** Each subset corresponds to a binary number from 0 to 2^n-1.

---

### 4. Single Number II (Medium)
**Question:** Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element.

**Solution:**
```cpp
int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int num : nums) {
        twos |= (ones & num);
        ones ^= num;
        int threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
    }
    return ones;
}
```
**Time:** O(n) | **Space:** O(1)

**Explanation:** Use two variables to track bits appearing once and twice. Clear when appearing thrice.

---

### 5. Bitwise AND of Numbers Range (Medium)
**Question:** Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range.

**Solution:**
```cpp
int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left < right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return left << shift;
}
```
**Time:** O(log n) | **Space:** O(1)

**Key Insight:** Find common prefix of left and right in binary representation.

---

## Amazon

### 1. Number of 1 Bits (Easy)
**Question:** Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

**Solution:**
```cpp
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        n &= (n - 1);  // Clear rightmost set bit
        count++;
    }
    return count;
}
```
**Time:** O(k) where k = number of set bits | **Space:** O(1)

**Brian Kernighan's Algorithm**

---

### 2. Reverse Bits (Easy)
**Question:** Reverse bits of a given 32 bits unsigned integer.

**Solution:**
```cpp
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}
```
**Time:** O(32) = O(1) | **Space:** O(1)

---

### 3. Power of Four (Easy)
**Question:** Given an integer n, return true if it is a power of four. Otherwise, return false.

**Solution:**
```cpp
bool isPowerOfFour(int n) {
    if (n <= 0) return false;
    // Must be power of 2 AND set bit at even position
    return (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
}
```
**Time:** O(1) | **Space:** O(1)

**Mask 0x55555555:** Binary 01010101... (1s at even positions)

---

### 4. UTF-8 Validation (Hard)
**Question:** Given an integer array data representing bytes, return whether it is a valid UTF-8 encoding.

**Solution:**
```cpp
bool validUtf8(vector<int>& data) {
    int numBytes = 0;
    int mask1 = 1 << 7;  // 10000000
    int mask2 = 1 << 6;  // 01000000
    
    for (int byte : data) {
        if (numBytes == 0) {
            int mask = 1 << 7;
            while (mask & byte) {
                numBytes++;
                mask >>= 1;
            }
            if (numBytes == 0) continue;
            if (numBytes == 1 || numBytes > 4) return false;
        } else {
            if (!((byte & mask1) && !(byte & mask2))) return false;
        }
        numBytes--;
    }
    return numBytes == 0;
}
```
**Time:** O(n) | **Space:** O(1)

---

### 5. Find the Difference (Easy)
**Question:** You are given two strings s and t. String t is generated by random shuffling string s and then add one more letter at a random position. Return the letter that was added.

**Solution:**
```cpp
char findTheDifference(string s, string t) {
    char result = 0;
    for (char c : s) result ^= c;
    for (char c : t) result ^= c;
    return result;
}
```
**Time:** O(n) | **Space:** O(1)

---

## Microsoft

### 1. Sum of Two Integers (Medium)
**Question:** Given two integers a and b, return the sum without using + or - operators.

**Solution:**
```cpp
int getSum(int a, int b) {
    while (b != 0) {
        unsigned int carry = (unsigned int)(a & b) << 1;
        a = a ^ b;  // Sum without carry
        b = carry;
    }
    return a;
}
```
**Time:** O(log n) | **Space:** O(1)

**Key:** XOR gives sum without carry. AND gives carry positions.

---

### 2. Divide Two Integers (Medium)
**Question:** Divide two integers without using multiplication, division, and mod operator.

**Solution:**
```cpp
int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    
    bool negative = (dividend < 0) ^ (divisor < 0);
    long long dvd = abs((long long)dividend);
    long long dvs = abs((long long)divisor);
    
    long long quotient = 0;
    while (dvd >= dvs) {
        long long temp = dvs, multiple = 1;
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        quotient += multiple;
    }
    return negative ? -quotient : quotient;
}
```
**Time:** O(log n)^2 | **Space:** O(1)

---

### 3. Total Hamming Distance (Medium)
**Question:** The Hamming distance between two integers is the number of positions at which the corresponding bits are different. Given an integer array nums, return the sum of Hamming distances between all pairs.

**Solution:**
```cpp
int totalHammingDistance(vector<int>& nums) {
    int total = 0;
    for (int i = 0; i < 32; i++) {
        int ones = 0;
        for (int num : nums) {
            ones += (num >> i) & 1;
        }
        int zeros = nums.size() - ones;
        total += ones * zeros;
    }
    return total;
}
```
**Time:** O(32 * n) = O(n) | **Space:** O(1)

**Key Insight:** For each bit position, count 1s and 0s. Contribution = ones * zeros.

---

### 4. Minimum XOR Value Pair (Medium)
**Question:** Find minimum XOR value of any pair in an array.

**Solution:**
```cpp
int minXOR(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int minXor = INT_MAX;
    for (int i = 0; i < arr.size() - 1; i++) {
        minXor = min(minXor, arr[i] ^ arr[i + 1]);
    }
    return minXor;
}
```
**Time:** O(n log n) | **Space:** O(1)

**Key:** Minimum XOR between adjacent elements in sorted array.

---

### 5. Binary Watch (Easy)
**Question:** A binary watch has 4 LEDs on top (hours) and 6 LEDs on bottom (minutes). Each LED represents a zero or one, with LSB on the right. Given an integer turnedOn, return all possible times the watch could represent.

**Solution:**
```cpp
vector<string> readBinaryWatch(int turnedOn) {
    vector<string> result;
    for (int h = 0; h < 12; h++) {
        for (int m = 0; m < 60; m++) {
            if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                result.push_back(to_string(h) + ":" + 
                    (m < 10 ? "0" : "") + to_string(m));
            }
        }
    }
    return result;
}
```
**Time:** O(1) - constant 12*60 iterations | **Space:** O(1)

---

## Apple

### 1. Complement of Base 10 Integer (Easy)
**Question:** The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

**Solution:**
```cpp
int bitwiseComplement(int n) {
    if (n == 0) return 1;
    int bitCount = 0, temp = n;
    while (temp) {
        bitCount++;
        temp >>= 1;
    }
    unsigned int mask = (1U << bitCount) - 1;
    return n ^ mask;
}
```
**Time:** O(log n) | **Space:** O(1)

---

### 2. Is Sparse Number (Medium)
**Question:** Check if a number has no consecutive set bits in its binary representation.

**Solution:**
```cpp
bool isSparse(int n) {
    return (n & (n << 1)) == 0;
}
```
**Time:** O(1) | **Space:** O(1)

**Explanation:** If consecutive 1s exist, AND will be non-zero.

---

### 3. Maximum Product of Word Lengths (Medium)
**Question:** Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.

**Solution:**
```cpp
int maxProduct(vector<string>& words) {
    int n = words.size();
    vector<int> masks(n, 0);
    
    for (int i = 0; i < n; i++) {
        for (char c : words[i]) {
            masks[i] |= (1 << (c - 'a'));
        }
    }
    
    int maxProd = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((masks[i] & masks[j]) == 0) {
                maxProd = max(maxProd, 
                    (int)(words[i].length() * words[j].length()));
            }
        }
    }
    return maxProd;
}
```
**Time:** O(n^2 + L) | **Space:** O(n)

---

### 4. Find Rightmost Set Bit Position (Easy)
**Question:** Find the position of the rightmost set bit.

**Solution:**
```cpp
int rightmostSetBit(int n) {
    if (n == 0) return 0;
    return log2(n & -n) + 1;
}
```
**Time:** O(1) | **Space:** O(1)

**Formula:** `n & -n` isolates rightmost set bit.

---

### 5. MSB Position (Medium)
**Question:** Find the position of the most significant bit.

**Solution:**
```cpp
int findMSB(int n) {
    if (n == 0) return 0;
    int pos = 0;
    while (n > 0) {
        n >>= 1;
        pos++;
    }
    return pos;
}
```
**Time:** O(log n) | **Space:** O(1)

---

## Netflix

### 1. XOR Queries of Subarray (Medium)
**Question:** Given arr and queries where queries[i] = [Li, Ri], return an array answer where answer[i] is XOR of elements from Li to Ri.

**Solution:**
```cpp
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size();
    vector<int> prefix(n + 1, 0);
    
    // Build prefix XOR array
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] ^ arr[i];
    }
    
    vector<int> result;
    for (auto& q : queries) {
        result.push_back(prefix[q[1] + 1] ^ prefix[q[0]]);
    }
    return result;
}
```
**Time:** O(n + q) | **Space:** O(n)

**Key:** XOR prefix array. `XOR(L, R) = prefix[R+1] ^ prefix[L]`

---

### 2. Largest Combination With Bitwise AND Greater Than Zero (Medium)
**Question:** Find the size of the largest subset where the bitwise AND of all elements is greater than zero.

**Solution:**
```cpp
int largestCombination(vector<int>& candidates) {
    int maxCount = 0;
    for (int i = 0; i < 32; i++) {
        int count = 0;
        for (int num : candidates) {
            if ((num >> i) & 1) count++;
        }
        maxCount = max(maxCount, count);
    }
    return maxCount;
}
```
**Time:** O(32 * n) = O(n) | **Space:** O(1)

**Key:** Maximum count of numbers having 1 at any bit position.

---

## Additional Companies

### LinkedIn: Hamming Distance (Easy)
```cpp
int hammingDistance(int x, int y) {
    int xorResult = x ^ y;
    return __builtin_popcount(xorResult);
}
```

### Uber: Swap Adjacent Bits (Medium)
```cpp
int swapAdjacentBits(int n) {
    // 0xAAAAAAAA = 10101010... (odd positions)
    // 0x55555555 = 01010101... (even positions)
    return ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
}
```

### Twitter: Flip Bits to Convert A to B (Medium)
```cpp
int bitSwapRequired(int a, int b) {
    return __builtin_popcount(a ^ b);
}
```

---

## 🎯 Pattern Recognition Guide

### When to use XOR:
- Finding unique/missing elements
- Swapping without temporary variable
- Checking if two numbers are different
- **Companies:** Google, Meta, Amazon

### When to use Bit Counting:
- Hamming distance/weight problems
- Total set bits calculations
- **Companies:** Amazon, Microsoft, Google

### When to use Bit Masking:
- Subset generation
- Character set representation
- State compression
- **Companies:** Meta, Apple, Google

### When to use Bit Shifts:
- Division/multiplication by powers of 2
- Building Trie for XOR problems
- **Companies:** Microsoft, Google

---

## 📊 Frequency by Company

| Company | Easy | Medium | Hard | Most Common Patterns |
|---------|------|--------|------|---------------------|
| Google | 1 | 4 | 0 | XOR, Trie, DP |
| Meta | 2 | 3 | 0 | XOR, Subset, Bit Count |
| Amazon | 4 | 0 | 1 | Basic Ops, Validation |
| Microsoft | 1 | 4 | 0 | Arithmetic, Distance |
| Apple | 3 | 2 | 0 | Masking, Position Finding |

---

## 💡 Interview Strategy

### Before the Interview:
1. ✅ Master basic operations (set, clear, toggle)
2. ✅ Understand XOR properties thoroughly
3. ✅ Practice Brian Kernighan's algorithm
4. ✅ Know common bit manipulation tricks

### During the Interview:
1. **Clarify** input constraints (negative numbers? overflow?)
2. **Think aloud** about bit patterns
3. **Start simple** - brute force first
4. **Optimize** using bit manipulation
5. **Test** with binary examples
6. **Discuss** time/space complexity

### Common Follow-ups:
- "What if numbers can be negative?"
- "Can you optimize space to O(1)?"
- "Handle overflow cases"
- "Explain why XOR works here"

---

## 🚀 Quick Reference

```cpp
// Essential operations for interviews
n & (n-1)           // Clear rightmost set bit
n & (-n)            // Isolate rightmost set bit
n | (1 << i)        // Set ith bit
n & ~(1 << i)       // Clear ith bit
n ^ (1 << i)        // Toggle ith bit
(n >> i) & 1        // Check ith bit
__builtin_popcount  // Count set bits
a ^ b               // XOR (find difference)
```

**Good luck with your interview! 🎉**
