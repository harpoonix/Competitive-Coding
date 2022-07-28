#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
using namespace std;

void solve() {
    
}

int main(){
    int n; cin>>n;
    int array[n];
    for (int i=0; i<n; i++) {
        cin>>array[i];
    }
    sort(array, array+n);
    int distinct=1;
    for (int i=1; i<n; i++) {
        if (array[i]>array[i-1]){
            distinct+=1;
        }
    }
    cout<<distinct<<endl;
}
