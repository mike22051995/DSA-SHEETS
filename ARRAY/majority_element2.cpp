#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,count2=0,nums1=0,nums2=0;
        for(int num:nums){
            if(num==nums1)count1++;
            else if(num==nums2)count2++;
            else if(count1==0 && num!=nums2){
                nums1=num;
                count1=1;
            }
            else if (count2==0 && num!=nums1){
                nums2=num;
                count2=1;
            }
            else count1--,count2--;
        }
        count1=0,count2=0;
        for(int num:nums){
            if(num==nums1)count1++;
            else if (num==nums2)count2++;
        }
        vector<int>res;
        if(count1>nums.size()/3)res.push_back(nums1);
        if(count2>nums.size()/3)res.push_back(nums2);
        return res;
        
    }
};