#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
    void helperForSubsequence(string &s, vector<string>&result,string &current,int index){
        if(index>=s.size()){
            result.push_back(current);
            return;
        }
        helperForSubsequence(s,result,current,index+1); //exclude
        current.push_back(s[index]);
        helperForSubsequence(s,result,current,index+1); //include
        current.pop_back(); //backtrack


    }
    public:
    vector<string> subsequence(string s){
        vector<string>result;
        string current="";
        helperForSubsequence(s,result,current,0);
        return result;
    }
  

};  
int main(){
    Solution sol;
    string s="abc";
    vector<string>res=sol.subsequence(s);
    cout<<"Subsequences are: "<<endl;
    for(auto str:res){
        cout<<"\""<<str<<"\" ";
    }
    cout<<endl;
    
    return 0;
}
