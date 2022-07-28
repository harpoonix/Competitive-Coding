#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
#define vi vector<int>
using namespace std;

long long dice_combiantions(int &n) {
    long long dice[n+1];
    int ans[7] = {1, 1, 2, 4, 8, 16, 32};
    if (n<=6) return ans[n];
    for (int i=0; i<7; i++) {
        dice[i] = ans[i];
    }
    for (int i=7; i<n+1; i++) {
        long long add = 0;
        for (int j=1; j<=6; j++) {
            add+=dice[i-j];
        }
        dice[i]=add%1000000007;
    }
    return dice[n];
}

int main(){
    int n; cin>>n;
    cout<<dice_combiantions(n)<<endl;
}
