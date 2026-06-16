/*
    Encode and Decode Strings - LeetCode #271 (Premium)
    
    Design an algorithm to encode a list of strings to a string. The encoded string
    is then sent over the network and decoded back to the original list of strings.
    
    Example:
    Input: ["lint","code","love","you"]
    Output: ["lint","code","love","you"]
    Explanation:
    One possible encode method is: "lint:;code:;love:;you"
    
    Constraints:
    - The string may contain any possible characters
    - Your encode and decode algorithms should be stateless
    
    Time Complexity: O(n) for both encode and decode
    Space Complexity: O(1) extra space
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Codec {
public:
    // Approach: Length prefix encoding
    // Format: [length]#[string][length]#[string]...
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& str : strs) {
            encoded += to_string(str.length()) + "#" + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        
        while (i < s.length()) {
            // Find the delimiter
            int delim = s.find('#', i);
            int length = stoi(s.substr(i, delim - i));
            
            // Extract the string
            string str = s.substr(delim + 1, length);
            decoded.push_back(str);
            
            // Move to next encoded string
            i = delim + 1 + length;
        }
        
        return decoded;
    }
};

int main() {
    Codec codec;
    
    // Test 1
    vector<string> test1 = {"lint", "code", "love", "you"};
    string encoded1 = codec.encode(test1);
    vector<string> decoded1 = codec.decode(encoded1);
    
    cout << "Test 1: ";
    for (const string& str : decoded1) {
        cout << str << " ";
    }
    cout << endl;
    
    // Test 2: With special characters
    vector<string> test2 = {"#", "##", "###"};
    string encoded2 = codec.encode(test2);
    vector<string> decoded2 = codec.decode(encoded2);
    
    cout << "Test 2: ";
    for (const string& str : decoded2) {
        cout << str << " ";
    }
    cout << endl;
    
    // Test 3: Empty strings
    vector<string> test3 = {"", "a", ""};
    string encoded3 = codec.encode(test3);
    vector<string> decoded3 = codec.decode(encoded3);
    
    cout << "Test 3: ";
    for (const string& str : decoded3) {
        cout << "\"" << str << "\" ";
    }
    cout << endl;
    
    return 0;
}
