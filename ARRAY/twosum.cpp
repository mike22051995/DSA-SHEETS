#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int,int>mp;
    
    for(int i=0;i<nums.size();i++){
        if(mp.find(target-nums[i])!=mp.end()){
            return {mp[target-nums[i]],i};
        }
        mp[nums[i]]=i;

    }

}
int main(){
    vector<int>nums={3,2,4};
    int target=6;
    vector<int>ans=twoSum(nums,target);
    cout<<ans[0]<<"and  "<<ans[1]<<endl;
    return 0;
}