// CodeForces 1654C
#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

void split(priority_queue<long long> &cake){
    long long piece = cake.top();
    long long half = piece/2;
    cake.pop();
    cake.push(half); cake.push(piece-half);
}

bool sequence(int *pcs, int n){
    long long weight=0;
    for (int i=0; i<n; i++) {
        weight+=pcs[i];
    }
    //cout<<"weight "<<weight<<"\n";
    priority_queue<int> a;
    for (int i=0; i<n; i++) {
        a.push(pcs[i]);
    }
    priority_queue<long long> cake;
    cake.push(weight);
    while(!a.empty() && !cake.empty()){
        if (cake.top()<a.top()){
            //cout<<"small\n";
            return false;
        }
        if (cake.top()==a.top()){
            cake.pop(); a.pop();
        }
        if (cake.top()>a.top()){
            split(cake);
        }
    }
    return (a.size()==0 && cake.size()==0 ? true : false);
}

void solve() {
    int n; cin>>n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    cout<<(sequence(a, n) ? "YES" : "NO")<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    for (int i=0; i<t; i++) {
        solve();
    }
}
