#include<iostream>
using namespace std;

class Solution{
    public:
    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }

};

int main(){
    Solution sol;
    int a=48,b=98;
    cout<<"GCD OF "<<a<<" and "<<b<<"  is: "<<sol.gcd(a,b)<<endl;
    return 0;
}