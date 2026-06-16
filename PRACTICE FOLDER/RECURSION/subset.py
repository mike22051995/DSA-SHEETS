"""

"""



if __name__ == "__main__":
    sol = Solution()
    vector<int>nums=[1,2,2,3]
    vector<vector<int>>res=sol.subSet(nums)
    for subset in res:
        print("[ ")
    for val in subset:
        print(val, end=" ")
    print(f"]")
