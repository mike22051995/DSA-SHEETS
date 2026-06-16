#include<iostream>
#include<string>
using namespace std;
 int countHousePlacements(int n) {
        unsigned long long leavespace=1;
        unsigned long long makeBuilding=1;
        for(int i=2;i<=n;i++){
            unsigned long long newbuilding=leavespace;
            unsigned long long newspace=(leavespace+makeBuilding)% 1000000007;
            makeBuilding=newbuilding;
            leavespace=newspace;

        }
        unsigned long long ans=leavespace+makeBuilding;
        return (ans*ans)% 1000000007;
    }
int main(){
    int n=2;
    cout<<countHousePlacements(n)<<endl;
    return 0;
}