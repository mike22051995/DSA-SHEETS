"""
PROBLEM: Maximum Frequency Stack (LeetCode 895)
DIFFICULTY: Hard
PATTERN: Stack with Frequency Tracking

DESCRIPTION:
Design a stack-like data structure that pops the most frequent element.
Implement FreqStack class:
- FreqStack() constructs an empty frequency stack
- void push(int val) pushes an integer val onto the top of the stack
- int pop() removes and returns the most frequent element. If tie, return the one closest to top

INPUT:
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
OUTPUT:
[null, null, null, null, null, null, null, 5, 7, 5, 4]

TIME COMPLEXITY: O(1) for both push and pop
SPACE COMPLEXITY: O(n) where n is number of elements

EXPLANATION:
Maintain:
1. freq: map from element to its frequency
2. group: map from frequency to stack of elements with that frequency
3. maxFreq: current maximum frequency
On push, increment frequency and add to appropriate frequency group.
On pop, return from maxFreq group and decrement frequency.
"""



from collections import defaultdict


class FreqStack:
    def __init__(self):
        self.freq = defaultdict(int)       # element -> frequency
        self.group = defaultdict(list)     # frequency -> stack of elements
        self.max_freq = 0

    def push(self, val: int) -> None:
        self.freq[val] += 1
        f = self.freq[val]
        self.max_freq = max(self.max_freq, f)
        self.group[f].append(val)

    def pop(self) -> int:
        val = self.group[self.max_freq].pop()
        self.freq[val] -= 1
        if not self.group[self.max_freq]:
            self.max_freq -= 1
        return val


if __name__ == "__main__":
    freqStack = FreqStack()
    print("Operations:")
    print("push(5), push(7), push(5), push(7), push(4), push(5)")
    freqStack.push(5)
    freqStack.push(7)
    freqStack.push(5)
    freqStack.push(7)
    freqStack.push(4)
    freqStack.push(5)
    print("\nPopping elements:")
    print(f"pop() = {freqStack.pop()}")
    print(f"pop() = {freqStack.pop()}")
    print(f"pop() = {freqStack.pop()}")
    print(f"pop() = {freqStack.pop()}")

    print("\n\nAnother test:")
    fs2 = FreqStack()
    print("push(4), push(0), push(9), push(3), push(4), push(2)")
    fs2.push(4)
    fs2.push(0)
    fs2.push(9)
    fs2.push(3)
    fs2.push(4)
    fs2.push(2)
    print(f"pop() = {fs2.pop()}")
