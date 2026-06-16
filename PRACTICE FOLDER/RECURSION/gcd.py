"""

"""

from typing import List, Optional

class Solution:
    def gcd(self, a, b):
        if b==0:
        return a
        return gcd(b,a%b)


if __name__ == "__main__":
    sol = Solution()
    a =48,b=98
    print(f"GCD OF {a}")
