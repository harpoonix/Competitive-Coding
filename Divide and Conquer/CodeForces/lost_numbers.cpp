// CodeForces 1167B
#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
#include <map>
#include <utility>
#define vi vector<int>
using namespace std;

void guess() {
    map<pair<int, int>, int> table;
    int nums[6] = {4, 8, 15, 16, 23, 42};
    for (int i=0; i<6; i++) {
        for (int j=0; j<6; j++) {
            table.emplace(make_pair(pair<int, int>(nums[i], nums[j]), nums[i]*nums[j]));
        }
    }
    /*
    for (auto x : table){
        cout<<"["<<x.first.first<<", "<<x.first.second<<"] "<<x.second<<endl;
    }
    */
    int result[6]={0};
    int prod1, prod2;
    for (int i=0; i<2; i++) {
        cout<<"? "<<1+3*i<<" "<<2+3*i<<endl;
        cin>>prod1;
        cout<<"? "<<2+3*i<<" "<<3+3*i<<endl;
        cin>>prod2;
        if (prod1==0 || prod2==0) return;
        int ans1[2], ans2[2];
        for (map<pair<int, int>, int>::iterator i = table.begin(); i!=table.end(); i++) {
            if (table[i->first] == prod1){
                ans1[0] = i->first.first; ans1[1] = i->first.second;
                break;
            }
        }
        for (map<pair<int, int>, int>::iterator i = table.begin(); i!=table.end(); i++) {
            if (table[i->first] == prod2){
                ans2[0] = i->first.first; ans2[1] = i->first.second;
                break;
            }
        }
        if (ans2[0]!=ans1[0] && ans2[1]!=ans1[0]){
            result[1+3*i] = ans1[1];
        }
        else {result[1+3*i] = ans1[0];}
        result[0+3*i] = prod1/result[1+3*i];
        result[2+3*i] = prod2/result[1+3*i];
    }
    cout<<"!";
    for (int i=0; i<6; i++) {
        cout<<" "<<result[i];
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    guess();
    return 0;
}
