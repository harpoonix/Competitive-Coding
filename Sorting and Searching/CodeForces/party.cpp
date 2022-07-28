//Codeforces 1610/C, others are 1613C, 1574C, 1612C, 1617C
#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
using namespace std;

bool possible(int*a, int*b, int target, int n){
    int poor=0;
    for (int i=0; i<n; i++) {
        if (poor<=b[i] && poor>=target-1-a[i]){
            poor+=1;
        }
        if (poor==target) return true;
    }
    return false;
}

int invite(int* a, int* b, int n){
    int min=0, max=n;
    while (max>min){
        int mid = (max+min)/2;
        if (mid==min) mid++;
        if (possible(a, b, mid, n)){
            min=mid;
        }
        else max=mid-1;
    }
    return max;
}

void solve() {
    int n; cin>>n;
    int a[n], b[n];
    for (int i=0; i<n; i++) {
        cin>>a[i]>>b[i];
    }
    cout<<invite(a, b, n)<<"\n";

}

int main(){
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    for (int i=0; i<t; i++) {
        solve();
    }
}
