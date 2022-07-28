// Codeforces 1697C
#include <iostream>
//#include <vector>
#include <string>
#include <algorithm>
#define vi vector<int>
using namespace std;

bool check_counts(string &s, string &t){
    int count[3][2]={0};
    for (string::iterator i = s.begin(); i<s.end(); i++) {
        int num = *i - 97;
        count[num][0]++;
    }
    for (string::iterator i = t.begin(); i<t.end(); i++){
        int num = *i-97;
        count[num][1]++;
    }
    for (int i=0; i<3; i++) {
        if (count[i][0]!=count[i][1]){
            //cout<<"check count false "<<count[i][0]<<" "<<count[i][1]<<"\n";
            return false;
        }
    }
    return true;
}

void solve() {
    int n; 
    cin>>n;
    string s, t;
    ws(cin);
    getline(cin, s);
    getline(cin, t);
    
    if(!check_counts(s, t)){cout<<"NO"<<"\n"; return;}
    int j=0;
    for (int i=0; i<n; i++) {
        if (s[i]=='b'){
            continue;
        }
        while (t[j]=='b'){
            j++;
        }
        if (s[i]!=t[j] || (s[i]=='a' && i>j) || (s[i]=='c' && i<j)){
            //cout<<s[i]<<" "<<t[j]<<"\n";
            cout<<"NO"<<"\n";
            return;
        }
        j++;
    }
    cout<<"YES"<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin>>q;
    for (int i=0; i<q; i++) {
        solve();
    }
}
