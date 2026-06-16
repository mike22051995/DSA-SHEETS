#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
    private:
    void helper(vector<int>&nums,vector<vector<int>>&result,int start){
        if(start>=nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i=start;i<nums.size();i++){
            swap(nums[start], nums[i]);
            helper(nums,result,start+1);
            swap(nums[start], nums[i]); // backtrack
        }
    }
    public:
    vector<vector<int>>permutation(vector<int>&nums){
        vector<vector<int>>result;
        helper(nums,result,0);
        return result;

    }

};
int main(){
    Solution sol;
    vector<int>nums={1,2,3};
    
 
    vector<vector<int>>result=sol.permutation(nums);
    for(auto res:result){
        cout<<"[";
        for(auto num:res){
            cout<<num<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}