#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>map;
        for( string s:strs){
            string sorted=s;
            sort(sorted.begin(),sorted.end());
            map[sorted].push_back(s);
        }
        vector<vector<string>>result;
        for(auto &m:map){
            result.push_back(m.second);
        }
        return result;
        
    }
int main(){
    vector<string>strs={"eat","tea","tan","ate","nat","bat"};
    
}