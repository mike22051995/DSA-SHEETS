/*
================================================================================
PROBLEM: Text Justification (LeetCode #68)
DIFFICULTY: Hard
PATTERN: String / Greedy
COMPANIES: Amazon, Microsoft, Facebook, Google, LinkedIn, Airbnb
================================================================================

PROBLEM DESCRIPTION:
Given an array of strings words and a width maxWidth, format the text such that
each line has exactly maxWidth characters and is fully (left and right) justified.
Pack words in a greedy approach; fit as many words as you can in each line.
Extra spaces should be distributed as evenly as possible. If spaces cannot be
distributed evenly, left slots get more spaces than right slots.

EXAMPLES:

Example 1:
Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Example 2:
Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]

PATTERN RECOGNITION:
Use this pattern when:
- Text formatting with specific width constraints
- Distribute spaces evenly
- Greedy packing with justification rules
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        
        while (i < words.size()) {
            int lineLen = words[i].length();
            int j = i + 1;
            
            // Find how many words fit in current line
            while (j < words.size() && lineLen + 1 + words[j].length() <= maxWidth) {
                lineLen += 1 + words[j].length();
                j++;
            }
            
            // Build line
            int numWords = j - i;
            int numSpaces = maxWidth - lineLen + (numWords - 1);
            
            string line;
            
            // Last line or single word - left justified
            if (j == words.size() || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line += string(maxWidth - line.length(), ' ');
            } else {
                // Middle lines - fully justified
                int spaceSlots = numWords - 1;
                int spacePerSlot = numSpaces / spaceSlots;
                int extraSpaces = numSpaces % spaceSlots;
                
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spaces = spacePerSlot + (k - i < extraSpaces ? 1 : 0);
                        line += string(spaces, ' ');
                    }
                }
            }
            
            result.push_back(line);
            i = j;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    
    auto result = sol.fullJustify(words, maxWidth);
    for (const auto& line : result) {
        cout << "\"" << line << "\"" << endl;
    }
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is total characters in all words
SPACE COMPLEXITY: O(n) for result

SIMILAR PROBLEMS:
1. Reorder Data in Log Files (LeetCode #937)
2. Valid Word Abbreviation (LeetCode #408)
3. String Compression (LeetCode #443)
4. Longest Word in Dictionary (LeetCode #720)
5. Design Search Autocomplete System (LeetCode #642)
6. Rearrange Spaces Between Words (LeetCode #1592)
7. Maximum Number of Words in Sentences (LeetCode #2114)
8. Split Message Based on Limit (LeetCode #2468)
9. Check If Two String Arrays are Equivalent (LeetCode #1662)
10. Length of Last Word (LeetCode #58)
*/
