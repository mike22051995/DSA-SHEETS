#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubarray(vector<int>&nums){
    int currsum=0;
    int maxsum=INT_MIN;
    for(int num:nums){
        currsum=max(num,num+currsum);
        maxsum=max(currsum,maxsum);

    }
    return maxsum;

}
int main(){
    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubarray(nums)<<endl;
    return 0;
}