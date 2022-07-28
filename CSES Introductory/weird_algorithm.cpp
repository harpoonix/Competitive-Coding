#include <iostream>
using namespace std;
void next(long unsigned int &x){
    if (x%2==0){
        x = x/2;
    }
    else x = 3*x+1;
}

void solve(long unsigned int n){
    while (n!=1){
        cout<<n<<" ";
        next(n);
    }
    cout<<1;
}

int main(){
    long unsigned int n; cin>>n;
    solve(n);
}