#include<iostream>
#include<vector>
using namespace std;
int CountPrime(int n){
    vector<bool>isprime(n,true);
    int count=0;
    for(int i=2;i<n;i++){
        if(!isprime[i])continue;
        count++;
        for(int j=2*i;j<n;j+=i){
            isprime[j]=false;
        }


    }
    return count;
}
int main(){
    int n=10;
    cout<<CountPrime(n)<<endl;
    return 0;
}