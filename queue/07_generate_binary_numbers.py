"""
PROBLEM: Generate Binary Numbers from 1 to N
Difficulty: Easy
Pattern: Queue-based Generation

DESCRIPTION:
Given a number N, generate binary numbers from 1 to N using a queue.
The idea is to use queue to generate binary representation by appending 
0 and 1 to previous binary numbers.

INPUT:
N = 5

OUTPUT:
1 10 11 100 101

INPUT:
N = 10

OUTPUT:
1 10 11 100 101 110 111 1000 1001 1010

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)
"""



if __name__ == "__main__":
    int n
    print("Enter N: ")
    cin >> n
    print(f"\nMethod 1 (Queue): ")
    binary = generateBinaryNumbers(n)
    for num in binary:
        print(num, end=" ")
    print()
    print(f"\nMethod 2 (Bit Manipulation): ")
    binaryAlt = generateBinaryNumbersAlt(n)
    for num in binaryAlt:
        print(num, end=" ")
    print()
    print(f"\n=== Test Cases ===")
    for test in [3, 8, 12]:
        print(f"N = {test}")
    res = generateBinaryNumbers(test)
    for num in res:
        print(num, end=" ")
    print()
