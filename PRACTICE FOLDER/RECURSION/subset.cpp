#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    void helper(vector<int>& nums,vector<vector<int>>& result,vector<int>& ans,int index){
        if(index>=nums.size()){
            result.push_back(ans);
            return;
        }
        
        // Include the current element
        ans.push_back(nums[index]);
        helper(nums,result,ans,index+1);
        ans.pop_back();
        
        // Skip duplicates before the "exclude" branch
        int nextIndex = index + 1;
        while(nextIndex < nums.size() && nums[nextIndex] == nums[index]){
            nextIndex++;
        }
        
        // Skip the current element (and all its duplicates)
        helper(nums,result,ans,nextIndex);
    }
    public:
    vector<vector<int>>subSet(vector<int>nums){ 
        vector<vector<int>>result;
        vector<int>ans;
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        helper(nums,result,ans,0);
        return result;

    }
};

int main(){
    Solution sol;
    vector<int>nums={1,2,2,3};
    vector<vector<int>>res=sol.subSet(nums);
    for(auto subset:res){
        cout<<"[ ";
        for(auto val:subset){
            cout<<val<<" ";
        }
        cout<<"]"<<endl;
    } 
    return 0;  

}   

