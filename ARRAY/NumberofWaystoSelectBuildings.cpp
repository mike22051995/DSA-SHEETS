/*2222. Number of Ways to Select Buildings*/
/*https://leetcode.com/problems/number-of-ways-to-select-buildings/description/*/
#include<iostream>
#include<string>
using namespace std;
long long numberOfWays(string s){
    long long count0=0,count1=0,count10=0,count01=0,count010=0,count101=0;
    for(char c:s){
        if(c=='0'){
            count0++;
            count10+=count1;
            count010+=count01;

        }
        else{
            count1++;
            count01+=count0;
            count101+=count10;
        }

    }
    return count010+count101;
}

int main(){
    string s="001101";
    cout<<numberOfWays(s)<<endl;
    return 0;
}