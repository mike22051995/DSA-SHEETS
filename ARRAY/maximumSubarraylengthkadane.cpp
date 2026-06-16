#include<iostream>
#include<unordered_set>
#include<climits>
#include<vector>
using namespace std;
int MaximumSubarrayL(vector<int>&nums){
    int currlen=0,maxlen=0;
    int maxsum=INT_MIN, currsum=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]+currsum>=nums[i]){
            currsum+=nums[i];
            currlen++;
        }
        else{
            currsum=nums[i];
            currlen=1;
        }
        if(currsum>maxsum){
            maxsum=currsum;
            maxlen=currlen;
        }
        else if(maxsum=currsum){
            maxlen=max(maxlen, currlen);
        }
    }
    return maxlen;
}