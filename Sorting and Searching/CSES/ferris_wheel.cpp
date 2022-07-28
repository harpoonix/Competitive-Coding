#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
using namespace std;

int gondolas(int n, int x, int* weights){
    int i=0, j=n-1, gondolas=0;
    while(i<=j){
        if (i==j){
            gondolas+=1;
            break;
        }
        if (weights[i]+weights[j]>x){
            gondolas+=1;
            j--;
        }
        else{
            gondolas+=1;
            i++; j--;
        }
    }
    return (gondolas);
}

int main(){
    int n, x;
    cin>>n>>x;
    int weights[n];
    for (int i=0; i<n; i++) {
        cin>>weights[i];
    }
    sort(weights, weights+n);
    cout<<gondolas(n, x, weights)<<endl;
}
