#include <iostream>
#include <string>
using namespace std;

int main(){
    int max_repeat=1; int repeat=0;
    char current, previous;
    string seq;
    getline(cin, seq);
    for (auto i=seq.begin(); i<seq.end(); i+=1){
        current=*i;
        if (repeat==0){repeat=1;}
        else if (repeat>0 && current==previous){
            repeat+=1;
        }
        else {
            repeat=1;
        }
        
        if (repeat>max_repeat){
                max_repeat=repeat;
        }
        previous=current;
    }
    cout<<max_repeat;
}