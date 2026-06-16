#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution{
    public:
    vector<vector<int>>targetSum(vector<int>&nums,int &target){
        unordered_set<int>seen;
        vector<vector<int>>result;
          
        for(auto num:nums){
            if(!seen.empty() && seen.count(target-num)){
                result.push_back({target-num,num});

                seen.erase(target -num); // to avoid duplicates
            }
            if(num==target){result.push_back({num});}
            seen.insert(num);

        }
        return result;
    }
    vector<vector<int>>twoSumIndex(vector<int>& nums, int target){
        unordered_map<int,int>map;
        vector<vector<int>>result;
        for(int i=0;i<nums.size();i++){
            if(!map.empty() && map.find(target-nums[i])!=map.end()){
                result.push_back({map[target-nums[i]],i});

            }
            map.insert({nums[i],i});
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int>nums={2,5,6,3,10,8,8,4,11};
    int target=10;
    vector<vector<int>>res=sol.twoSumIndex(nums,target);
    for(auto pair:res){
        cout<<"["<<pair[0]<<","<<pair[1]<<"]"<<endl;
    } 
    return 0;  

}

