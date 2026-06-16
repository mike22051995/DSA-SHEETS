"""
PROBLEM: Circular Tour (Petrol Pump)
Difficulty: Easy-Medium
Pattern: Queue/Circular Array

DESCRIPTION:
Given petrol and distance for N petrol pumps arranged in a circle,
find the starting point from where a truck can complete the circular tour.
The truck has unlimited capacity.

INPUT:
Petrol:   [4, 6, 7, 4]
Distance: [6, 5, 3, 5]

OUTPUT:
Starting Index: 1

Explanation: If we start from index 1:
- At pump 1: petrol = 6, distance = 5, remaining = 1
- At pump 2: petrol = 7 + 1 = 8, distance = 3, remaining = 5
- At pump 3: petrol = 4 + 5 = 9, distance = 5, remaining = 4
- At pump 0: petrol = 4 + 4 = 8, distance = 6, remaining = 2
Successfully completed tour!

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
"""



if __name__ == "__main__":
    print(f"=== Test Case 1 ===")
    pumps1 = 
    [4, 6],
    [6, 5],
    [7, 3],
    [4, 5]
    start1 = circularTourOptimal(pumps1)
    print(f"Starting Index: {start1}")
    verifyTour(pumps1, start1)
    print(f"\n=== Test Case 2 ===")
    pumps2 = 
    [1, 5],
    [10, 3],
    [3, 4]
    start2 = circularTourOptimal(pumps2)
    print(f"Starting Index: {start2}")
    verifyTour(pumps2, start2)
    print(f"\n=== Test Case 3 (No Solution) ===")
    pumps3 = 
    [2, 5],
    [3, 6],
    [1, 4]
    start3 = circularTourOptimal(pumps3)
    print(f"Starting Index: {start3}")
    verifyTour(pumps3, start3)
