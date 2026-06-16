#include<iostream>
#include<string>
#include<vector>
using namespace std;
 string longestCommonPrefix(vector<string>& strs){
    string prefix=strs[0];
    for(int i=1;i<strs.size();i++){
        while(strs[i].find(prefix)!=0){
            prefix=prefix.substr(0,prefix.size()-1);
        }
    }
    return prefix;
 }
 int main(){
    vector<string>strs={"dog","racecar","car"};
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
 }