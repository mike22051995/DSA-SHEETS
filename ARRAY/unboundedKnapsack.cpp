#include<iostream>
#include<vector>
using namespace std;
int KnapsackU(vector<int>&val,vector<int>&wt,int capacity){
    vector<int>dp(capacity+1,0);
    for(int i=1;i<=capacity;i++){
        for(int j=0;j<wt.size();j++){
            if(wt[j]<=i){
                dp[i]=max(dp[i-wt[j]]+val[j],dp[i]);
            }
        }
    }
    return dp[capacity];
}

int main(){
    vector<int>val={6,1,7,7};
    vector<int>wt={1,3,4,5};
    int capacity=8;
    cout<<KnapsackU(val,wt,capacity)<<endl;
    return 0;
}