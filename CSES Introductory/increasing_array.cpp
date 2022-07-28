#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    long unsigned int array[n];
    for (int i=0; i<n; i+=1){
        cin>>array[i];
    }
    long unsigned int max_till_now=array[0];
    long unsigned int moves=0;
    for (int i=1; i<n; i+=1){
        if (array[i]<max_till_now){
            moves+=max_till_now-array[i];
        }
        if (array[i]>max_till_now){
            max_till_now=array[i];
        }
    }
    cout<<moves;
}