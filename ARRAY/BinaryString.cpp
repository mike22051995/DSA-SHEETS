#include<iostream>
#include<vector>
using namespace std;

void Backtrack(int n,string curr,vector<string>&result){
    if(curr.size()==n){
        result.push_back(curr);
        return ;
    }
    Backtrack(n,curr+'1',result);
    if(curr.empty()||curr.back()!='0'){
        Backtrack(n,curr+'0',result);
    }

}



vector<string> validStrings(int n){
    vector<string>result;
    Backtrack(n,"",result);
    return result;
}

int main(){
    int n=6;
    vector<string>ans=validStrings(n);
    for(string s:ans){
        cout<<s<<"  ";
    }
    return 0;
}