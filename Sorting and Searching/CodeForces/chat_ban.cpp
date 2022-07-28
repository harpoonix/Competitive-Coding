// Codeforces 1612C
#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
#define vi vector<int>
#define ll long long int
using namespace std;

ll binary_search(ll &k, ll &x, bool more_than_half){
    if (more_than_half){
        ll start = k, end = 2*k-1;
        ll mid;
        while (end>start){
            mid = (start+end)/2;
            if ((k*(k+1)/2 + (mid-k)*(3*k-mid-1)/2) >= x){
                end=mid;
            }
            else start=mid+1;
        }
        return end;
    }
    else {
        ll start = 1, end = k;
        ll mid;
        while (end>start){
            mid = (start+end)/2;
            if ((mid*(mid+1)/2) >= x){
                end=mid;
            }
            else start=mid+1;
        }
        return end;
    }
}

ll banhammer(ll &k, ll &x){
    ll msg;
    if (x > (ll)k*(k+1)/2 ){
        msg = binary_search(k,x, true);
    }
    else msg = binary_search(k, x, false);
    return msg;
}

void solve() {
    ll k, x;
    cin>>k>>x;
    cout<<banhammer(k ,x)<<"\n";

}

int main(){
    int t; cin>>t;
    for (int i=0; i<t; i++) {
        solve();
    }
}
