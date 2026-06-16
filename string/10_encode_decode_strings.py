"""
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
"""

from typing import List

class Codec:
    # Approach: Length prefix encoding
    # Format: [length]#[string][length]#[string]...
    def encode(self, strs: List[str]) -> str:
        encoded = ""
        for s in strs:
            encoded += str(len(s)) + "#" + s
        return encoded

    def decode(self, s: str) -> List[str]:
        decoded = []
        i = 0
        
        while i < len(s):
            # Find the delimiter
            delim = s.index('#', i)
            length = int(s[i:delim])
            
            # Extract the string
            string = s[delim + 1:delim + 1 + length]
            decoded.append(string)
            
            # Move to next encoded string
            i = delim + 1 + length
        
        return decoded

if __name__ == "__main__":
    codec = Codec()
    
    # Test 1
    test1 = ["lint", "code", "love", "you"]
    encoded1 = codec.encode(test1)
    decoded1 = codec.decode(encoded1)
    print(f"Test 1: {decoded1}")
    
    # Test 2: With special characters
    test2 = ["#", "##", "###"]
    encoded2 = codec.encode(test2)
    decoded2 = codec.decode(encoded2)
    print(f"Test 2: {decoded2}")
    
    # Test 3: Empty strings
    test3 = ["", "a", ""]
    encoded3 = codec.encode(test3)
    decoded3 = codec.decode(encoded3)
    print(f"Test 3: {decoded3}")
