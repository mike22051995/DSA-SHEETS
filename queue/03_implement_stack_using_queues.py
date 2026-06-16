"""
PROBLEM: Implement Stack using Queues
Difficulty: Easy
Pattern: Queue to Stack Conversion

DESCRIPTION:
Implement a stack using two queues with operations:
- push(x): Push element to stack
- pop(): Remove and return top element
- top(): Get top element
- empty(): Check if stack is empty

INPUT:
Operations: push(1), push(2), top(), pop(), empty()

OUTPUT:
Top: 2
Popped: 2
Empty: False

TIME COMPLEXITY: 
- push(): O(n)
- pop(), top(), empty(): O(1)
SPACE COMPLEXITY: O(n)
"""



if __name__ == "__main__":
    print(f"=== Version 1: Push costly ===")
    Stack s1
    s1.push(1)
    s1.push(2)
    s1.push(3)
    print(f"Top: {s1.top()}")
    print(f"Popped: {s1.pop()}")
    print(f"Top: {s1.top()}")
    print(f"\n=== Version 2: Pop costly ===")
    StackV2 s2
    s2.push(10)
    s2.push(20)
    s2.push(30)
    print(f"Top: {s2.top()}")
    print(f"Popped: {s2.pop()}")
    print(f"Top: {s2.top()}")
