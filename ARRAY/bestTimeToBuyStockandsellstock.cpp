#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit=0;
        for(int price:prices){
            if(price>buy){
                profit=max(price-buy,profit);
            }
            buy=min(buy,price);
        }
        return profit;
        
    }
};
int main(){
    vector<int>nums={4,7,5,4,3,9,5,1,23};
    Solution s1;
    cout<<s1.maxProfit(nums)<<endl;
}