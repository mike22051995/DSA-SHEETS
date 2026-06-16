/*https://leetcode.com/problems/count-and-say/description/*/
/*Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with 
the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" 
we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".*/

#include<iostream>
#include<string>
using namespace std;
string CountAndSay(int n){
    if(n==1){ return "1";}
    string prev=CountAndSay(n-1),res="";
    for(int i=0;i<prev.size();){
        int count=0;
        while(i+count<prev.size() && prev[i]==prev[i+count]) count++;
        res+=to_string(count)+prev[i];
        i+=count;
    }
    return res;
}
int main(){
    int n=20;
    cout<<CountAndSay(n)<<endl;
    return 0;
}