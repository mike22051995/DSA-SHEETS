/*
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
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

// Method 1: Using Queue and Frequency Map
string firstNonRepeating(string stream) {
    unordered_map<char, int> freq;
    queue<char> q;
    string result = "";
    
    for (char ch : stream) {
        // Increment frequency
        freq[ch]++;
        
        // Add to queue
        q.push(ch);
        
        // Remove repeating characters from front
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }
        
        // First element in queue is first non-repeating
        if (q.empty()) {
            result += '#';
        } else {
            result += q.front();
        }
    }
    
    return result;
}

// Method 2: Using Array for frequency (faster for small character set)
string firstNonRepeatingOptimized(string stream) {
    int freq[26] = {0};
    queue<char> q;
    string result = "";
    
    for (char ch : stream) {
        // Increment frequency
        freq[ch - 'a']++;
        
        // Add to queue
        q.push(ch);
        
        // Remove repeating characters from front
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }
        
        // First element in queue is first non-repeating
        if (q.empty()) {
            result += '#';
        } else {
            result += q.front();
        }
    }
    
    return result;
}

// Print step-by-step for better understanding
void printStepByStep(string stream) {
    unordered_map<char, int> freq;
    queue<char> q;
    
    cout << "Stream: " << stream << endl;
    cout << "\nStep-by-step:" << endl;
    
    for (int i = 0; i < stream.length(); i++) {
        char ch = stream[i];
        freq[ch]++;
        q.push(ch);
        
        // Clean queue
        queue<char> tempQ = q;
        while (!tempQ.empty() && freq[tempQ.front()] > 1) {
            tempQ.pop();
        }
        
        cout << "After '" << ch << "': ";
        if (tempQ.empty()) {
            cout << "#";
        } else {
            cout << tempQ.front();
        }
        cout << " (Freq: ";
        for (auto& p : freq) {
            cout << p.first << ":" << p.second << " ";
        }
        cout << ")" << endl;
        
        // Update main queue
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }
    }
}

int main() {
    // Test case 1
    string stream1 = "aabcc";
    cout << "=== Test Case 1 ===" << endl;
    printStepByStep(stream1);
    cout << "Result: " << firstNonRepeating(stream1) << endl;
    
    // Test case 2
    cout << "\n=== Test Case 2 ===" << endl;
    string stream2 = "aabc";
    printStepByStep(stream2);
    cout << "Result: " << firstNonRepeating(stream2) << endl;
    
    // Test case 3
    cout << "\n=== Test Case 3 ===" << endl;
    string stream3 = "aabbcd";
    cout << "Stream: " << stream3 << endl;
    cout << "Result: " << firstNonRepeating(stream3) << endl;
    
    // Test case 4
    cout << "\n=== Test Case 4 ===" << endl;
    string stream4 = "abcabc";
    cout << "Stream: " << stream4 << endl;
    cout << "Result: " << firstNonRepeating(stream4) << endl;

    return 0;
}

/*
EXPLANATION:

1. Use queue to maintain order of characters
2. Use frequency map to track character counts
3. For each new character:
   - Increment its frequency
   - Add to queue
   - Remove characters from front if frequency > 1
   - Front of queue is first non-repeating character

WHY QUEUE?
- Maintains insertion order
- Quick access to first non-repeating character
- Efficient removal of repeating characters from front

KEY INSIGHTS:
- Queue stores only potential candidates
- Frequency map tracks actual counts
- Lazy deletion: Remove when checking, not when frequency increases
- O(1) amortized time per character

KEY LEARNING POINTS:
- Classic queue + hash map pattern
- Common in Google, Amazon interviews
- Streaming data processing pattern
- Similar to: LRU Cache, Sliding Window problems
*/
