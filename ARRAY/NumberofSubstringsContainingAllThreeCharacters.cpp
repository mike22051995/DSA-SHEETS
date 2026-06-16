#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int numberOfSubstrings(string s){
    vector<int>last_seen={-1,-1,-1};
    int count=0;
    for(int i=0;i<s.size();++i){
        last_seen[s[i]-'a']=i;
        if(last_seen[0]!=-1 && last_seen[1]!=-1 && last_seen[2]!=-1){
            count+=(1+min({last_seen[0],last_seen[1],last_seen[2]}));
        }
    }
    return count;
}