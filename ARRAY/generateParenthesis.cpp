#include<iostream>
#include<string>
#include<vector>
using namespace std;
void backtrack(int o, int c,string curr,vector<string>&result){
    if(o==0 && c==0){
        result.push_back(curr);
    
    }
    if(o>0){
        backtrack(o-1,c,curr+"(",result);
    }
    if(c>o){
        backtrack(o,c-1,curr+")",result);
    }
 }

vector<string> generateParenthesis(int n){
    vector<string>result;
    backtrack(n,n,"",result);
    return result;
 }
 
 int main(){
    int n;
    cout<<"please enter the number"<<endl;
    cin>>n;
    vector<string>parenth;
    parenth=generateParenthesis(n);
    for(string s:parenth){
        cout<<s<<"  ";
    }
    return 0;

 }