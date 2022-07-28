// CodeForces 1696A
#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
#define vi vector<int>
using namespace std;

void solve() {
    int n, z;
    cin>>n>>z;
    int a[n];
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    for (int i=0; i<n; i++) {
        a[i] = a[i] | z;
    }
    int max = a[0];
    for (int i=1; i<n; i++) {
        if (a[i]>max){
            max=a[i];
        }
    }
    cout<<max<<endl;
}

int main(){
    int t; cin>>t;
    for (int i=0; i<t; i++) {
        solve();
    }
}
