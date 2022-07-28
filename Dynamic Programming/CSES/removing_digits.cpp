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
    int dp[n+1]; //dp[i] = Minimum number of operations to go from x to zero
    dp[0]=0;
    for (int i=1; i<n+1; i++) {
        dp[i] = 9999999;
    }
    for (int i=1; i<n+1; i++) {
        int dig, k = i;
        while(k!=0){
            dig = k%10;
            dp[i] = min(dp[i], dp[i-dig]+1);
            k/=10;
        }
    }
    cout<<dp[n]<<endl;
}
