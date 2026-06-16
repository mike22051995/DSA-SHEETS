#include<stack>
#include<vector>
#include<iostream>

using namespace std;
vector<int>dailyTemperature(vector<int>&temperatures){
    stack<int>stk;
    vector<int>answer(temperatures.size(),0);
    for(int i=0;i<temperatures.size();i++){
        while(!stk.empty() && temperatures[i]>temperatures[stk.top()]){
            answer[stk.top()]=i-stk.top();
            stk.pop();
        }
        stk.push(i);
    }
    return answer;
}

int main(){
    vector<int>temperatures={73,74,75,71,69,72,76,73};
    vector<int>result=dailyTemperature(temperatures);
    for(int day:result){
        cout<<day<<"  ";
    }
    return 0;

}