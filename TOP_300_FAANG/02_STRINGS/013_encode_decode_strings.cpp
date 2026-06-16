/*
================================================================================
PROBLEM: Encode and Decode Strings (LeetCode #271)
DIFFICULTY: Medium
PATTERN: String Encoding
COMPANIES: Amazon, Facebook, Google, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Codec {
public:
    // Encodes a list of strings to a single string
    string encode(vector<string>& strs) {
        string encoded;
        
        for (string& str : strs) {
            encoded += to_string(str.length()) + "#" + str;
        }
        
        return encoded;
    }

    // Decodes a single string to a list of strings
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        
        while (i < s.length()) {
            int delimPos = s.find('#', i);
            int length = stoi(s.substr(i, delimPos - i));
            
            string str = s.substr(delimPos + 1, length);
            result.push_back(str);
            
            i = delimPos + 1 + length;
        }
        
        return result;
    }
};

class CodecAlt {
public:
    // Alternative: using escape character
    string encode(vector<string>& strs) {
        string result;
        
        for (string& str : strs) {
            for (char c : str) {
                if (c == '/') {
                    result += "//";
                } else {
                    result += c;
                }
            }
            result += "/:";
        }
        
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string current;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '/') {
                if (i + 1 < s.length() && s[i + 1] == ':') {
                    result.push_back(current);
                    current.clear();
                    i++;
                } else if (i + 1 < s.length() && s[i + 1] == '/') {
                    current += '/';
                    i++;
                }
            } else {
                current += s[i];
            }
        }
        
        return result;
    }
};

int main() {
    Codec codec;
    vector<string> strs = {"Hello", "World", "Test#123"};
    
    string encoded = codec.encode(strs);
    cout << "Encoded: " << encoded << endl;
    
    vector<string> decoded = codec.decode(encoded);
    cout << "Decoded: ";
    for (string& str : decoded) {
        cout << str << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Serialize and Deserialize Binary Tree (LeetCode #297)
2. Serialize and Deserialize BST (LeetCode #449)
3. Serialize and Deserialize N-ary Tree (LeetCode #428)
4. Count and Say (LeetCode #38)
5. String Compression (LeetCode #443)
6. Design Compressed String Iterator (LeetCode #604)
7. Encode and Decode TinyURL (LeetCode #535)
8. Decode String (LeetCode #394)
9. Decode Ways (LeetCode #91)
10. External Sort
*/
