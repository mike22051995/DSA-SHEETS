/*https://leetcode.com/problems/maximum-product-subarray/description/*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxProduct(vector<int>& nums) {
        int mx=nums[0],mn=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(mx,mn);
            }
            mx=max(nums[i],mx*nums[i]);
            mn=min(nums[i],mn*nums[i]);
            ans=max(mx,ans);
        
        }
        return ans;
    }
int main(){
    vector<int>nums={2,4,5,-1,3,-2};
    cout<<maxProduct(nums)<<endl;
    return 0;
}