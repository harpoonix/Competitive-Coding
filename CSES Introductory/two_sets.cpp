#include <iostream>
#include <vector>
using namespace std;

void solve(int n){
    vector<int> vec1, vec2;
    int rem=n%4;
    int quo=n/4;
    if (rem==1||rem==2){
        cout<<"NO"; return;
    }
    if (rem==3){
        cout<<"YES\n"<<2*quo+2<<endl<<"1 2 ";
        for (int i=4; i<=n; i+=4){
            cout<<i<<" "<<i+3<<" ";
        }
        cout<<endl<<2*quo+1<<endl<<"3 ";
        for (int i=5; i<=n; i+=4){
            cout<<i<<" "<<i+1<<" ";
        }
    }
    if (rem==0){
        cout<<"YES\n"<<2*quo<<endl;
        for (int i=1; i<=n; i+=4){
            cout<<i<<" "<<i+3<<" ";
        }
        cout<<endl<<2*quo<<endl;
        for (int i=2; i<=n; i+=4){
            cout<<i<<" "<<i+1<<" ";
        }
    }
}


int main(){
    int n; cin>>n;
    solve(n);
}
