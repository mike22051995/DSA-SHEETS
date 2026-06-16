#include<iostream>
#include<String>
#include<vector>
using namespace std;
 bool isPalindrome(string s) {
    int i=0, j=s.size()-1;
    while(i<j){
        if(!isalnum(s[i])) i++;
        else if (!isalnum(s[j])) j--;
        else{
            if(tolower(s[i++])!=tolower(s[j--])) return false;
        }
    }
    return true;

 }
 int main(){
    string s="race a car";
    cout<<isPalindrome(s)<<endl;
    return 0;

 }