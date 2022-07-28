#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;

bool good(vvi &a){
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<a[0].size()-1; j++) {
            if (a[i][j]>a[i][j+1]){
                //cout<<"not good\n";
                return false;
            }
        }
    }
    return true;
}

void check(vvi &a, int *p){
    for (int i=0; i<a.size(); i++) {
        vi b(a[i].begin(), a[i].end());
        sort(b.begin(), b.end());
        int mismatch=0;
        for (int j=0; j<a[0].size(); j++) {
            if (b[j]!=a[i][j]){
                if (mismatch>=2) {
                    //cout<<"mismatch more than 2\n"; 
                    p[0]=-1; return;
                }
                p[mismatch]=j;
                mismatch+=1;
            }
        }
        if (mismatch==2){
            return;
        }
    }
}

void swap(vvi &a, int *p){
    for (int i=0; i<a.size(); i++) {
        swap(a[i][p[0]], a[i][p[1]]);
    }
}

void solve() {
    int n, m; cin>>n>>m;
    vvi a;
    a.resize(n, vi(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>a[i][j];
        }
    }
    if (good(a)){
        cout<<1<<" "<<1<<"\n";
        return;
    }
    vi mismatch;
    for (int i=0; i<n; i++) {
        vi b(a[i].begin(), a[i].end());
        sort(b.begin(), b.end());
        for (int j=0; j<m; j++) {
            if (b[j]!=a[i][j]){
                mismatch.push_back(j);
            }
        }
    }
    if (mismatch.size()>2){
        cout<<-1<<endl;
        return;
    }
    if (mismatch.size()==2){
        for (int i=0; i<n; i++) {
            swap(a[i][mismatch[0]], a[i][mismatch[1]]);
        }
    }
    //swap(a, p);
    //cout<<p[0]<<" "<<p[1]<<"\n";
    if (good(a)){
        cout<<mismatch[0]+1<<" "<<mismatch[1]+1<<"\n";
        return;
    }
    else {
        cout<<-1<<"\n";
        return;
    }

}

int main(){
    int t; cin>>t;
    for (int i=0; i<t; i++) {
        solve();
    }
}
