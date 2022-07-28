#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
using namespace std;
int n;
/*
struct Ticket{
    bool sold; int price;
    Ticket(){
        sold=false;
    };
    Ticket(int prc){
        sold=false; price=prc;
    }
    bool operator<(Ticket t){
        return (price<t.price);
    }
};
*/

int ticket(int* prices, bool* sold, int max, int start, int end) {
    if (start==end){
        if (sold[start]==true){
            if (start==0){return -1;}
            return ticket(prices, sold, max, start-1, end-1);
        }
        int val=prices[start];
        if (val>max){return -1;}
        if (end==n-1 && n>5){
            n--;
            return val;
        }
        sold[start]=true;
        return val;
    }
    int mid=start+(end-start)/2;
    if (mid==start){mid+=1;}
    if (prices[mid]>max){
        return ticket(prices, sold, max, start, mid-1);
    }
    else {
        return ticket(prices, sold, max, mid, end);
    }
}

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m;
    cin>>n>>m;
    int customers[m];
    int prices[n];
    bool sold[n]={0};
    for (int i=0; i<n; i++) {
        cin>>prices[i];
    }
    for (int i=0; i<m; i++) {
        cin>>customers[i];
    }
    sort(prices, prices+n);

    for (int i=0; i<m; i++) {
        cout<<ticket(prices, sold, customers[i], 0, n-1)<<"\n";
    }

}
