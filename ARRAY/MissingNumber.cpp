/*https://leetcode.com/problems/missing-number/submissions/1662995365/*/

/*Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int missingNumber(vector<int>& nums) {
    int ans=nums.size();
    for(int i=0;i<nums.size();++i){
        ans^=i^nums[i];
    }
    return ans;
}

int main(){
    vector<int>nums={9,6,4,2,3,5,7,0,1};
    cout<<missingNumber(nums)<<endl;
    return 0;
}
