"""
PROBLEM: First Non-Repeating Character in Stream
Difficulty: Easy
Pattern: Queue + Frequency Array

DESCRIPTION:
Given a stream of characters, find the first non-repeating character 
at each point. If no non-repeating character exists, return '#'.

INPUT:
Stream: "aabcc"

OUTPUT:
After 'a': a
After 'a': #
After 'b': b
After 'c': b
After 'c': b

INPUT:
Stream: "aabc"

OUTPUT:
After 'a': a
After 'a': #
After 'b': b
After 'c': b

TIME COMPLEXITY: O(n) where n is length of stream
SPACE COMPLEXITY: O(26) = O(1) for lowercase English letters
"""



if __name__ == "__main__":
    stream1 = "aabcc"
    print(f"=== Test Case 1 ===")
    printStepByStep(stream1)
    print(f"Result: {firstNonRepeating(stream1)}")
    print(f"\n=== Test Case 2 ===")
    stream2 = "aabc"
    printStepByStep(stream2)
    print(f"Result: {firstNonRepeating(stream2)}")
    print(f"\n=== Test Case 3 ===")
    stream3 = "aabbcd"
    print(f"Stream: {stream3}")
    print(f"Result: {firstNonRepeating(stream3)}")
    print(f"\n=== Test Case 4 ===")
    stream4 = "abcabc"
    print(f"Stream: {stream4}")
    print(f"Result: {firstNonRepeating(stream4)}")
