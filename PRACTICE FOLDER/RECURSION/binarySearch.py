"""

"""

from typing import List, Optional

class Solution:
    def binarySearch(self, vector<int>nums, target, left, right):
        if(left>right) return -1
        mid =left+(right-left)/2
        if(nums[mid]==target) return mid
        if(nums[mid]>target) return binarySearch(nums,target,left,mid-1)
        return binarySearch(nums,target,mid+1,right)


if __name__ == "__main__":
    sol = Solution()
    vector<int>nums=[1,2,3,4,5,7,8,9]
    print(sol.binarySearch(nums,8 ,0,len(nums)-1), end="")
