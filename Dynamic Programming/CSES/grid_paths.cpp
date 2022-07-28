#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
#define vi vector<int>
using namespace std;

void solve() {
    
}

int main(){
    int n; cin>>n;
    char c;
    int grid[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>c;
            if (c=='.'){
                grid[i][j] = 1;
            }
            else grid[i][j]=0;
        }
    }
    if (grid[0][0]==0){cout<<0<<endl; return 0;}
    long long dp[n][n]; // Let dp[r][c] represent the number of ways to go to row r and column c
    dp[0][0]=1; // we start at (0, 0)
    for (int i=1; i<n; i++) {
        if (!grid[i][0]) {
            dp[i][0]=0;
        }
        else {
            dp[i][0]=dp[i-1][0];
        }
        if (!grid[0][i]){
            dp[0][i]=0;
        }
        else {
            dp[0][i]=dp[0][i-1];
        }
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<n; j++) {
            if (!grid[i][j]){
                dp[i][j]=0;
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                dp[i][j]%=1000000007;
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;
}
