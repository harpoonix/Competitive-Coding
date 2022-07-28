// Codeforces 1613C
#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
#define vi vector<int>
#define ll long long int
using namespace std;

bool kill(ll &k, ll &h, int *attack, int &n){
    ll health = h; ll damage=0;
    for (int i=0; i<n; i++) {
        if (i==n-1) {damage = k;}
        else {
            damage = attack[i]+k <= attack[i+1] ? k : attack[i+1]-attack[i];
        }
        health-=damage;
        //cout<<"damage "<<damage;
        if (health<=0) break;
    }
    //cout<<"k and final health are "<<k<<" "<<health<<endl;
    return health<=0 ? true : false;
}

ll time(int *attack, ll &h, int &n){
    ll min = 1, max = __LONG_LONG_MAX__;
    //cout<<max<<endl;
    ll mid;
    while (max>min){
        mid = min + (max-min)/2;
        //cout<<mid<<endl;
        if (kill(mid, h, attack, n)){
            max = mid;
        }
        else min = mid+1;
    }
    return min;
}

void solve() {
    int n; long long int h;
    cin>>n>>h;
    int attack[n];
    for (int i=0; i<n; i++) {
        cin>>attack[i];
    }
    cout<<time(attack, h, n)<<"\n";

}

int main(){
    int t; cin>>t;
    for (int i=0; i<t; i++) {
        solve();
    }
}
