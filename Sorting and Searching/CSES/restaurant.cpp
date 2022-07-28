#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
using namespace std;

struct Event{
    char c; int time; //'a' for arrival, 'd' for departure
    Event(){};
    Event(char ch, int t){
        time=t; c=ch;
    }
    bool operator<(Event e){
        return (time < e.time);
    }
};

int solve(Event* list, int n) {
    int current=0, max_customers=0;
    sort(list, list+n);
    for (int i=0; i<n; i++) {
        if (list[i].c=='a'){
            current+=1;
        }
        else {
            if (current>max_customers){
                max_customers=current;
            }
            current-=1;
        }
    }
    return max_customers;
}

int main(){
    int n; cin>>n;
    Event customers[2*n];
    for (int i=0; i<2*n; i+=2){
        customers[i].c='a'; cin>>customers[i].time;
        customers[i+1].c='d'; cin>>customers[i+1].time;
    }
    cout<<solve(customers, 2*n)<<endl;

}
