// CodeForces 1111C 
#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
#include <cmath>
#define vi vector<int>
#define ll long long int
using namespace std;

int n, k; ll A, B;

int avenger_count(int s, int e, int* av){
    int start=0, end=k-1;
    int mid;
    while (end>start){
        mid = (start+end)/2;
        if (av[mid]>=s){
            end = mid;
        }
        else start = mid + 1;
    }
    int l_pos = end;

    start = 0; end = k-1;
    while (end>start){
        mid = (start+end)/2;
        if (mid==start) mid++;
        if (av[mid]<=e){
            start = mid;
        }
        else end = mid - 1;
    }
    int r_pos = end;
    if (s>av[k-1] && e>av[k-1]){return 0;}
    if (s<av[0] && e<av[0]){return 0;}
    //cout<<l_pos<<" "<<r_pos<<endl;
    //cout<<"No of avengers between "<<s<<" and "<<e<<" are "<<r_pos - l_pos + 1<<endl;
    return r_pos - l_pos + 1;
}

ll power(int start, int end, int* av) {
    ll burn_now;
    int no_of = avenger_count(start, end, av);
    if (no_of==0){
        return A;
    }
    else burn_now = B*(end-start+1)*no_of;
    if (start==end){
        return burn_now;
    }
    int mid = (start+end)/2;
    return min(burn_now, power(start, mid, av) + power(mid+1, end, av));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k>>A>>B;
    int av[k];
    for (int i=0; i<k; i++) {
        cin>>av[i];
    }
    int end = pow(2, n) + 1e-3;
    sort(av, av+k);
    cout<<power(1, end, av)<<endl;
    
}
