#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int numarr[n];
    for (int i=0; i<n; i+=1){numarr[i]=0;}
    int temp;
    for (int i=0; i<n-1; i+=1){
        cin>>temp;
        numarr[temp-1]=1;
    }
    for (int i=0; i<n; i+=1){
        if (numarr[i]==0){
            cout<<i+1;
            break;
        }
    }

}