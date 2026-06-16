#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int binarySearch(vector<int>&nums,int target,int left,int right){
        if(left>right) return -1;
        int mid=left+(right-left)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]>target) return binarySearch(nums,target,left,mid-1);
        return binarySearch(nums,target,mid+1,right);


    }
};

int main(){
    Solution sol;


    vector<int>nums={1,2,3,4,5,7,8,9};
    cout<<sol.binarySearch(nums,8 ,0,nums.size()-1);
    return 0;
    

}
