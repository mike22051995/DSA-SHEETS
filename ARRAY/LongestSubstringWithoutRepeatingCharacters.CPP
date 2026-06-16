#include<iostream>

#include<unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s){
    unordered_map<char,int>mp;
    int l=0,r=0,maxlen=0,newlen=0;
    while(r<s.size()){
        if(mp.find(s[r])!=mp.end()){
            l=mp[s[r]]+1;
        }
        newlen=r-l+1;
        maxlen=max(maxlen,newlen);
        mp[s[r]]=r;
        r++;
    }
    return maxlen;
}
int main(){
    string s = "abcabcbb";
    cout<<lengthOfLongestSubstring(s)<<endl;
}
