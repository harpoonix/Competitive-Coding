#include <iostream>
#include <cmath>
using namespace std;

void tower(int start, int end, int other, int n){
    if (n==2){
        cout<<start<<" "<<other<<"\n";
        cout<<start<<" "<<end<<"\n";
        cout<<other<<" "<<end<<"\n";
        return;
    }
    tower(start, other, end, n-1);
    cout<<start<<" "<<end<<"\n";
    tower(other, end, start, n-1);
    return;
}

int main(){
    int n; cin>>n;
    cout<<(int)(pow(2, n)-1+1e-3)<<endl; //no. of moves
    if (n==1){
        cout<<"1 3\n";
        return 0;
    }
    tower(1, 3, 2, n);
}