#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_set<int>mp;
    long long currsum=0, maxsum=INT8_MIN;
    int currlen=0, maxlen=0,l=0;
    for(int r=0;r<nums.size();++r){
        while(mp.count(nums[r])){
            currsum-=nums[l];
            mp.erase(nums[l]);
            l++;
        }
        currsum+=nums[r];
        mp.insert(nums[r]);
        if(r-l+1==k){
            maxsum=max(maxsum, currsum);
            currsum-=nums[l];
            mp.erase(nums[l]);
            l++;

        }
    }
    return maxsum;

}
int main(){
    vector<int>nums={1,5,4,2,9,9,9};
    int k=3;
    cout<<maximumSubarraySum(nums,k)<<endl;
    return 0;
}