#include <iostream>
using namespace std;

bool solve(long int &a, long int &b){
    int rem = (a+b)%3;
    if (rem!=0){
        return false;
    }
    if (a<=2*b && 2*a>=b){
        return true;
    }
    return false;
}

int main(){
    int t; cin>>t;
    long int a, b;
    for (int i=0; i<t; i+=1){
        cin>>a>>b;
        if (solve(a,b)){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
}