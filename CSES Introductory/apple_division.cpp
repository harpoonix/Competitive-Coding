#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n; cin>>n;
    long int arr[n];
    for (int i=0; i<n; i+=1){
        cin>>arr[i];
    }
    long int diff=-99;
    for (long i=0; i<pow(2, n)+1e-3; i+=1){
        long sum1=0, sum2=0;
        for (int j=0; j<n; j+=1){
            if (i>>j & 1){
                sum1+=arr[j];
            }
            else sum2+=arr[j];
        }
        if (diff==-99){
            diff=abs(sum1-sum2);
        }
        diff=min(diff, abs(sum1-sum2));
    }
    cout<<diff;
}