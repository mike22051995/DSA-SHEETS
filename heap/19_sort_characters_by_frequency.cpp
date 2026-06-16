#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given a string s, sort characters in decreasing order by frequency.

Sample Input/Output:
1) s="tree" -> "eetr" or "eert"
2) s="cccaaa" -> "aaaccc" or "cccaaa"
3) s="Aabb" -> "bbAa" or "bbaA"

Code Explanation:
Count character frequency and push {frequency, character} into max-heap.
Build output by popping highest frequency first.
*/

string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    priority_queue<pair<int, char>> maxHeap;
    for (auto &entry : freq) maxHeap.push({entry.second, entry.first});

    string result;
    while (!maxHeap.empty()) {
        pair<int, char> top = maxHeap.top();
        maxHeap.pop();
        int f = top.first;
        char c = top.second;
        result.append(f, c);
    }
    return result;
}

int main() {
    cout << "Output 1: " << frequencySort("tree") << "\n";
    cout << "Output 2: " << frequencySort("cccaaa") << "\n";
    cout << "Output 3: " << frequencySort("Aabb") << "\n";
    return 0;
}
