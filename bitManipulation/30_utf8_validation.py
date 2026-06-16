"""
PROBLEM: UTF-8 Validation
===========================
Given an array of integers representing data, determine if it is a 
valid UTF-8 encoding.

APPROACH:
- UTF-8 rules:
  * 1-byte: 0xxxxxxx
  * 2-byte: 110xxxxx 10xxxxxx
  * 3-byte: 1110xxxx 10xxxxxx 10xxxxxx
  * 4-byte: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
- Check first byte to determine character length
- Verify following bytes start with 10xxxxxx

PATTERN: Bit Masking for Format Validation

INPUT/OUTPUT:
Input: data = [197,130,1]
Output: True
Explanation: Valid 2-byte char (197,130) + 1-byte char (1)
197 = 11000101, 130 = 10000010, 1 = 00000001

Input: data = [235,140,4]
Output: False
Explanation: 235 = 11101011 expects 3-byte but 4 = 00000100 is invalid

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def validUtf8(self, data):
        numBytesToProcess = 0
        # Masks for checking
        mask1 = 1 << 7;  # 10000000
        mask2 = 1 << 6;  # 01000000
        for byte in data:
        if numBytesToProcess == 0:
        # Determine number of bytes in current UTF-8 character
        mask = 1 << 7
        while mask & byte:
        numBytesToProcess += 1
        mask >>= 1
        # 1-byte character
        if (numBytesToProcess == 0) continue
        # Invalid: should be between 2 and 4
        if numBytesToProcess == 1 or numBytesToProcess > 4:
        return False
        } else 
        # Check if byte starts with 10xxxxxx
        if (!((byte & mask1) and !(byte & mask2))):
        return False
        numBytesToProcess -= 1
        return numBytesToProcess == 0


if __name__ == "__main__":
    sol = Solution()
    data1 = [197, 130, 1]
    print(f"Input: [197,130,1]")
    print(f"Binary representation:")
    for byte in data1:
        print(byte, end=" = ")
    printBinary(byte)
    print()
    print(f"Output: {(sol.validUtf8(data1)}")
    print(f"Explanation: Valid 2-byte + 1-byte character")
    data2 = [235, 140, 4]
    print(f"Input: [235,140,4]")
    print(f"Binary representation:")
    for byte in data2:
        print(byte, end=" = ")
    printBinary(byte)
    print()
    print(f"Output: {(sol.validUtf8(data2)}")
    print(f"Explanation: Invalid UTF-8 sequence")
    data3 = [240, 162, 138, 147]
    print(f"Input: [240,162,138,147]")
    print(f"Binary representation:")
    for byte in data3:
        print(byte, end=" = ")
    printBinary(byte)
    print()
    print(f"Output: {(sol.validUtf8(data3)}")
    print(f"Explanation: Valid 4-byte character")
