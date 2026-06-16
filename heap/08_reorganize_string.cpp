#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given a string s, rearrange characters so no two adjacent characters are same.
If impossible, return empty string.

Sample Input/Output:
1) s = "aab" -> "aba"
2) s = "aaab" -> ""
3) s = "vvvlo" -> one valid output: "vlvov"

Code Explanation:
Use max-heap of {frequency, character}. Pop top two most frequent chars,
append both, reduce frequency, and push back if still available.
*/

string reorganizeString(string s) {
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;

    priority_queue<pair<int, char>> maxHeap;
    for (int i = 0; i < 26; i++) if (freq[i] > 0) maxHeap.push({freq[i], char('a' + i)});

    string result;
    while (maxHeap.size() >= 2) {
        pair<int, char> first = maxHeap.top(); maxHeap.pop();
        pair<int, char> second = maxHeap.top(); maxHeap.pop();

        int f1 = first.first;
        char c1 = first.second;
        int f2 = second.first;
        char c2 = second.second;

        result.push_back(c1);
        result.push_back(c2);

        if (--f1 > 0) maxHeap.push({f1, c1});
        if (--f2 > 0) maxHeap.push({f2, c2});
    }

    if (!maxHeap.empty()) {
        pair<int, char> last = maxHeap.top();
        int f = last.first;
        char c = last.second;
        if (f > 1) return "";
        result.push_back(c);
    }
    return result;
}

int main() {
    cout << "Output 1: " << reorganizeString("aab") << "\n";
    cout << "Output 2: " << reorganizeString("aaab") << "\n";
    cout << "Output 3: " << reorganizeString("vvvlo") << "\n";
    return 0;
}
