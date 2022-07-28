#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
using namespace std;

struct myTime{
    int time; char c;
    myTime(){};
    myTime(int t, char a){
        time=t; c=a;
    }
    bool operator<(myTime bruh){
        return (time < bruh.time);
    }
};

int max_overlap(myTime list[], int n) {
    int overlap=0, largest_overlap=0;
    for (int i=0; i<n; i++) {
        if (list[i].c=='s'){
            overlap+=1;
        }
        else if (list[i].c=='e'){
            overlap-=1;
        }
        if (overlap>largest_overlap){
            largest_overlap=overlap;
        }
    }
    return largest_overlap;
}

int main(){
    int n; cin>>n;
    myTime times[2*n];
    for (int i=0; i<2*n; i+=2) {
        times[i].c='s'; cin>>times[i].time;
        times[i+1].c='e'; cin>>times[i+1].time;
    }
    sort(times, times+2*n);
    cout<<max_overlap(times, 2*n)<<endl;
}
