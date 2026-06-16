# Bit Manipulation - FAANG Interview Preparation 🚀

## Overview
This collection contains **30 carefully curated bit manipulation problems** covering all essential patterns and techniques commonly asked in FAANG interviews. Each problem includes detailed explanations, multiple approaches, time/space complexity analysis, and comprehensive test cases.

## 📚 Problem Categories

### Easy Problems (1-10)
Foundation concepts and basic bit operations

| # | Problem | Key Pattern | Complexity |
|---|---------|-------------|------------|
| 01 | Check Power of 2 | Clear Rightmost Bit | O(1) |
| 02 | Count Set Bits | Brian Kernighan's Algorithm | O(log n) |
| 03 | Single Number | XOR Properties | O(n) |
| 04 | Reverse Bits | Bit-by-Bit Processing | O(1) |
| 05 | Check ith Bit | Bit Checking | O(1) |
| 06 | Set ith Bit | Bit Setting | O(1) |
| 07 | Clear ith Bit | Bit Clearing | O(1) |
| 08 | Toggle ith Bit | Bit Toggling | O(1) |
| 09 | XOR from 1 to N | XOR Pattern | O(1) |
| 10 | Swap Without Temp | XOR Swap | O(1) |

### Medium Problems (11-22)
Advanced techniques and combinations

| # | Problem | Key Pattern | Complexity |
|---|---------|-------------|------------|
| 11 | Missing Number | XOR for Missing Element | O(n) |
| 12 | Single Number II | Bit Counting (3 times) | O(n) |
| 13 | Single Number III | XOR with Partitioning | O(n) |
| 14 | Power of Four | Power Checking | O(1) |
| 15 | Generate Subsets | Binary Representation | O(n * 2^n) |
| 16 | Gray Code | Gray Code Generation | O(2^n) |
| 17 | Bitwise AND Range | Common Prefix | O(log n) |
| 18 | Count Total Set Bits | Pattern Recognition | O(log n) |
| 19 | Rightmost Set Bit | Bit Isolation | O(1) |
| 20 | Find the Difference | XOR for Characters | O(n) |
| 21 | Maximum XOR (Two Numbers) | Trie with Bits | O(n * 32) |
| 22 | Complement Base 10 | Bit Flipping with Mask | O(log n) |

### Hard Problems (23-30)
Complex algorithms and advanced patterns

| # | Problem | Key Pattern | Complexity |
|---|---------|-------------|------------|
| 23 | Divide Integers | Division with Bit Shifts | O(log n)² |
| 24 | Minimum XOR Pair | XOR with Sorting | O(n log n) |
| 25 | Max Product Word Lengths | Bitmask for Characters | O(n²) |
| 26 | Find MSB Position | MSB Detection | O(log n) |
| 27 | Check Sparse Number | Consecutive Bits Check | O(1) |
| 28 | Binary String Substrings | Binary Matching | O(n log n) |
| 29 | Counting Bits | DP with Bits | O(n) |
| 30 | UTF-8 Validation | Bit Masking Validation | O(n) |

## 🎯 Key Patterns Covered

### 1. Basic Operations
- Setting, clearing, toggling bits
- Checking specific bit positions
- Finding rightmost/leftmost set bits

### 2. XOR Properties
- Finding unique elements
- Swapping without temporary variables
- XOR from range calculations
- Character/number differences

### 3. Bit Counting
- Brian Kernighan's algorithm
- Pattern-based counting
- Dynamic programming with bits

### 4. Power Checking
- Power of 2, 4, etc.
- Sparse number detection

### 5. Bit Manipulation with Data Structures
- Trie for maximum XOR
- Bitmasks for subset representation
- Character set encoding

### 6. Range Operations
- Bitwise AND of range
- XOR in range patterns

### 7. Advanced Techniques
- Gray code generation
- Binary representation matching
- UTF-8 validation
- Division without operators

## 🔑 Essential Bit Manipulation Tricks

```cpp
// 1. Check if power of 2
(n & (n-1)) == 0

// 2. Turn off rightmost set bit
n & (n-1)

// 3. Isolate rightmost set bit
n & (-n)

// 4. Check if ith bit is set
(n & (1 << i)) != 0

// 5. Set ith bit
n | (1 << i)

// 6. Clear ith bit
n & ~(1 << i)

// 7. Toggle ith bit
n ^ (1 << i)

// 8. Check if number is even
(n & 1) == 0

// 9. Multiply/Divide by 2^k
n << k  // multiply
n >> k  // divide

// 10. Swap two numbers
a ^= b; b ^= a; a ^= b;
```

## 📖 How to Use This Collection

### For Interview Preparation:
1. **Week 1**: Master Easy problems (1-10)
   - Focus on understanding basic bit operations
   - Practice until you can solve without reference

2. **Week 2**: Tackle Medium problems (11-22)
   - Learn pattern recognition
   - Understand when to apply each technique

3. **Week 3**: Challenge yourself with Hard problems (23-30)
   - Combine multiple patterns
   - Optimize solutions

### Study Strategy:
1. **Read** the problem description carefully
2. **Try** to solve it yourself first (15-20 minutes)
3. **Review** the provided solution and explanation
4. **Code** it again from scratch
5. **Test** with edge cases
6. **Explain** the solution out loud (mock interview practice)

## 🚀 Compilation and Execution

### Compile any file:
```bash
g++ -std=c++17 01_check_power_of_2.cpp -o problem01
./problem01
```

### Or compile and run directly:
```bash
g++ -std=c++17 01_check_power_of_2.cpp && ./a.out
```

## 💡 Interview Tips

1. **Always verify edge cases:**
   - n = 0
   - n = 1
   - Negative numbers
   - Maximum/minimum integer values

2. **Discuss time/space complexity** before coding

3. **Think out loud** - explain your approach

4. **Start with brute force**, then optimize

5. **Test your code** with examples before submitting

6. **Know these common complexities:**
   - O(1) - Direct bit operations
   - O(log n) - Processing each bit
   - O(n) - Linear scan with bit operations
   - O(n * 2^n) - Subset generation

## 🎓 Common Interview Questions

These 30 problems cover variations of questions asked at:
- **Google**: Problems 3, 11, 13, 21, 25, 29
- **Meta/Facebook**: Problems 2, 12, 15, 17, 23
- **Amazon**: Problems 1, 5-8, 14, 20, 22
- **Microsoft**: Problems 4, 9, 16, 18, 24, 28
- **Apple**: Problems 10, 19, 26, 27, 30

## 📝 Additional Resources

- **LeetCode Tags**: Bit Manipulation
- **Practice**: Solve variations of these problems
- **Time yourself**: Aim for 20-25 minutes per problem

## 🎯 Success Metrics

After completing this collection, you should be able to:
- ✅ Recognize bit manipulation patterns instantly
- ✅ Solve easy problems in < 10 minutes
- ✅ Solve medium problems in < 20 minutes
- ✅ Approach hard problems systematically
- ✅ Explain time/space complexity confidently
- ✅ Handle edge cases without prompting

## 🏆 Final Tips for Friday's Interview

1. **Get good sleep** the night before
2. **Review patterns** (not individual problems)
3. **Practice explaining** your thought process
4. **Stay calm** - you've prepared well!
5. **Ask clarifying questions** before coding
6. **Write clean, readable code**
7. **Test thoroughly** with examples

---

**Good luck with your FAANG interview! 🚀**

*Remember: Bit manipulation is all about patterns. Once you master these 30 problems, you'll be ready for any bit manipulation question!*
