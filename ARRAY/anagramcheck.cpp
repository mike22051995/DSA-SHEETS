#include<iostream>
#include<vector>
#include<string>
/*https://leetcode.com/problems/valid-anagram/*/
using namespace std;
 bool isAnagram(string s, string t){
    vector<int>map(26,0);
    if(s.size()!=t.size()) return false;
    for(int i=0;i<s.size();i++){
        map[s[i]]++;
        map[t[i]]--;
    }
    for(int num:map){
        if(num!=0) return false;
    }
    return true;
 }
 int main(){
    string s ="anagram";
    string t="nagaram";
    cout<<isAnagram(s,t)<<endl;
    return 0;


 }