#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
#define vi vector<int>
using namespace std;

long long ways(int n, int x, int* coins) {
    long long dp[x+1];
    dp[0] = 1;
    for (int i=1; i<x+1; i++) {
        long long add=0;
        for (int j=0; j<n; j++) {
            if (i-coins[j]>=0){
                add+=dp[i-coins[j]];
            }
        }
        dp[i]=add%1000000007;
    }
    return dp[x];
}

int main(){
    int n, x; cin>>n>>x;
    int coins[n];
    for (int i=0; i<n; i++) {
        cin>>coins[i];
    }
    cout<<ways(n, x, coins)<<endl;
}
