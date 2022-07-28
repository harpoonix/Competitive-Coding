#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
#define vi vector<int>
using namespace std;

int ways(int n, int x, int* coins){
    int dp[n+1][x+1];
     //dp[i][j] is the number of ways to reach target j using only the first i coins
    for (int i=0; i<n+1; i++) {
        dp[i][0]=1;
    }
    for (int i=0; i<x+1; i++) {
        dp[0][i]=0;
    }
    dp[0][0] = 1;
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<x+1; j++) {
            dp[i][j] = (dp[i-1][j] + (j-coins[i-1]>=0 ? dp[i][j-coins[i-1]] : 0))%1000000007;
        }
    }
    return dp[n][x];
}

int main(){
    int n, x; cin>>n>>x;
    int coins[n];
    for (int i=0; i<n; i++) {
        cin>>coins[i];
    }
    cout<<ways(n, x, coins)<<endl;
}

