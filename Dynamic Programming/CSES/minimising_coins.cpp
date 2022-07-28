#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
#define vi vector<int>
using namespace std;

int minimum(int n, int x, int *coins) {
    // Let dp[i] is the minimum number of coins to produce a sum of i
    int dp[x+1];
    dp[0]=0;
    for (int i=1; i<x+1; i++) {
        dp[i]=9999999;
    }
    for (int i=1; i<x+1; i++) {
        for (int j=0; j<n; j++) {
            dp[i] = min(dp[i], (i-coins[j]>=0 ? dp[i-coins[j]]+1 : INT32_MAX-1));
        }
    }
    return dp[x]!=9999999 ? dp[x]:-1;
}

int main(){
    int n, x; cin>>n>>x;
    int coins[n];
    for (int i=0; i<n; i++) {
        cin>>coins[i];
    }
    cout<<minimum(n, x, coins)<<endl;
}
