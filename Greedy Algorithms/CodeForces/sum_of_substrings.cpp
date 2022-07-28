// CodeForces 1691C
#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
#define vi vector<int>
using namespace std;

int f(int*s, int &n){
    int sum = 10*s[0] + s[n-1];
    for (int i=1; i<n-1; i++) {
        sum+=11*s[i];
    }
    return sum;
}

int min_f(int* s, int &n, int &k){
    int first=n-1, last=0; long int op;
    for (int i=0; i<n; i++) {
        if (s[i]==1){
            first = i;
            break;
        }
    }
    for (int i=n-1; i>=0; i--) {
        if (s[i]==1){
            last=i;
            break;
        }
    }
    // n-1-last operations to get 1 to last
    // rest operations to see if we can get 1 in the beginning
    if (n-1-last>k) {
        if (first>k){
            return f(s, n);
        }
        swap(s[0], s[first]);
        return f(s, n);
    }
    op = n-1-last;
    swap(s[last], s[n-1]);
    if (op+first>k || first==last){
        return f(s, n);
    }
    swap(s[0], s[first]);
    // op+=first;
    return f(s, n);

}

void solve() {
    int n, k; cin>>n>>k;
    int s[n]; char c;
    for (int i=0; i<n; i++) {
        cin>>c;
        s[i] = c-'0';
    }
    cout<<min_f(s, n, k)<<endl;
}

int main(){
    int t; cin>>t;
    for (int i=0; i<t; i++) {
        solve();
    }
}
