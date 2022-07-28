#include <iostream>
using namespace std;

int main(){
    long int n; cin>>n;
    int res=0;
    long int num=n;
    for (int i=5; num>0; i*=5){
        num=n/i;
        res+=num;
    }
    cout<<res;
}