#include <iostream>
//#include <cmath>
using namespace std;

void solve(){
    long long int x, y;
    cin>>y>>x;
    bool comp = (x<=y);
    long long int m;
    if (comp){
        m=y;
    }
    else {m=x;}
    long long int l = (m-1)*(m-1);
    if (m%2==1){
        if (comp){
            cout<< l + x <<endl; return;
        }
        else {
            cout<<l + 2*m-y <<endl; return;
        }
    }
    else {
        if (!comp){
            cout<< l + y <<endl; return;
        }
        else {
            cout<< l + 2*m-x <<endl; return;
        }
    }
}

int main(){
    int t; cin>>t;
    for (int i=0; i<t; i+=1){
        solve();
    }
}