/*
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
*/

#include <iostream>
#include <vector>
using namespace std;

struct PetrolPump {
    int petrol;
    int distance;
};

// Method 1: Brute Force - O(n²)
int circularTourBruteForce(vector<PetrolPump>& pumps) {
    int n = pumps.size();
    
    // Try each pump as starting point
    for (int start = 0; start < n; start++) {
        int petrol = 0;
        int count = 0;
        int current = start;
        
        // Try to complete tour
        while (count < n) {
            petrol += pumps[current].petrol;
            petrol -= pumps[current].distance;
            
            // Can't reach next pump
            if (petrol < 0) {
                break;
            }
            
            current = (current + 1) % n;
            count++;
        }
        
        // Successfully completed tour
        if (count == n && petrol >= 0) {
            return start;
        }
    }
    
    return -1; // No solution
}

// Method 2: Optimal - O(n) Single Pass
int circularTourOptimal(vector<PetrolPump>& pumps) {
    int n = pumps.size();
    int totalPetrol = 0;
    int currentPetrol = 0;
    int start = 0;
    
    for (int i = 0; i < n; i++) {
        int balance = pumps[i].petrol - pumps[i].distance;
        
        totalPetrol += balance;
        currentPetrol += balance;
        
        // If current petrol becomes negative, start from next pump
        if (currentPetrol < 0) {
            start = i + 1;
            currentPetrol = 0;
        }
    }
    
    // If total petrol >= 0, tour is possible
    return (totalPetrol >= 0) ? start : -1;
}

// Method 3: Using Queue (demonstration purpose)
int circularTourQueue(vector<PetrolPump>& pumps) {
    int n = pumps.size();
    int start = 0;
    int end = 1;
    int currentPetrol = pumps[start].petrol - pumps[start].distance;
    
    // If single pump
    if (n == 1) {
        return (currentPetrol >= 0) ? 0 : -1;
    }
    
    while (start != end || currentPetrol < 0) {
        // Remove pumps from start while current petrol is negative
        while (currentPetrol < 0 && start != end) {
            currentPetrol -= (pumps[start].petrol - pumps[start].distance);
            start = (start + 1) % n;
            
            // If start reaches end, no solution
            if (start == 0) {
                return -1;
            }
        }
        
        // Add pump to end
        currentPetrol += (pumps[end].petrol - pumps[end].distance);
        end = (end + 1) % n;
    }
    
    return start;
}

// Detailed verification
void verifyTour(vector<PetrolPump>& pumps, int start) {
    if (start == -1) {
        cout << "No valid starting point exists!" << endl;
        return;
    }
    
    int n = pumps.size();
    int petrol = 0;
    int current = start;
    
    cout << "\nVerification from index " << start << ":" << endl;
    
    for (int i = 0; i < n; i++) {
        petrol += pumps[current].petrol;
        cout << "At pump " << current << ": ";
        cout << "Got " << pumps[current].petrol << " petrol, ";
        cout << "Total = " << petrol << ", ";
        cout << "Need " << pumps[current].distance << ", ";
        
        petrol -= pumps[current].distance;
        cout << "Remaining = " << petrol << endl;
        
        if (petrol < 0) {
            cout << "Failed! Cannot reach next pump." << endl;
            return;
        }
        
        current = (current + 1) % n;
    }
    
    cout << "Success! Completed the tour." << endl;
}

int main() {
    // Test case 1
    cout << "=== Test Case 1 ===" << endl;
    vector<PetrolPump> pumps1 = {
        {4, 6},
        {6, 5},
        {7, 3},
        {4, 5}
    };
    
    int start1 = circularTourOptimal(pumps1);
    cout << "Starting Index: " << start1 << endl;
    verifyTour(pumps1, start1);
    
    // Test case 2
    cout << "\n=== Test Case 2 ===" << endl;
    vector<PetrolPump> pumps2 = {
        {1, 5},
        {10, 3},
        {3, 4}
    };
    
    int start2 = circularTourOptimal(pumps2);
    cout << "Starting Index: " << start2 << endl;
    verifyTour(pumps2, start2);
    
    // Test case 3: No solution
    cout << "\n=== Test Case 3 (No Solution) ===" << endl;
    vector<PetrolPump> pumps3 = {
        {2, 5},
        {3, 6},
        {1, 4}
    };
    
    int start3 = circularTourOptimal(pumps3);
    cout << "Starting Index: " << start3 << endl;
    verifyTour(pumps3, start3);
    
    return 0;
}

/*
EXPLANATION:

Optimal Algorithm (Greedy):
1. Keep track of total petrol balance
2. Try to complete tour from current start
3. If balance becomes negative, move start to next position
4. If total balance >= 0, tour is possible from 'start'

KEY INSIGHTS:
- If sum(petrol) >= sum(distance), solution exists
- If we can't reach pump i from start, we can't reach it from any pump between start and i
- This is because each intermediate pump would have less accumulated petrol
- So skip all intermediate pumps and start from i+1

WHY IT WORKS:
- If total petrol >= total distance, there must be a solution
- Starting point is where we never go negative after that point
- Greedy choice: Skip all failing starting points

KEY LEARNING POINTS:
- Classic circular array problem
- Greedy algorithm with proof
- Common in Amazon, Google interviews
- Practice problem: GFG Circular Tour
*/
