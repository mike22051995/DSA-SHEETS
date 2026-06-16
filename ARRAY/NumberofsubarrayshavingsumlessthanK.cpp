#include<iostream>
#include<vector>
using namespace std;

int NumberofsubarrayshavingsumlessthanK(vector<int>&nums,int k){
    int sm=nums[0];
    int l=0,r=0, count=0;
    while(r<nums.size() && l<nums.size()){
        while(sm>k){
            sm-=nums[l];
            l++;

        }
        while(sm<k){
            r++;
            
            if(r>=l){
                count+=l-r;

            }
            if(r<nums.size()){
                sm+=nums[r];
            }
            

        }
    }
}

