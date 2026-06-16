#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
void NextPemutation(vector<int>&nums){
    int i=nums.size()-2;
    while(i>=0 && nums[i]>=nums[i+1]){
       
        i--;
    }
    if(i>=0){
        int j=nums.size()-1;
        while(j>=0 && nums[j]<=nums[i]){
            j--;
        }
        swap(nums[i],nums[j]);
    }
    reverse(nums.begin()+i+1,nums.end());
    
    
}


int main(){
    vector<int>nums={1,3,5,4,2};
    NextPemutation(nums);
    for(int num:nums){
        cout<<num<<endl;
    }
    return 0;
    

    }
