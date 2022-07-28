#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    sort(str.begin(), str.end());
    vector<string> vec;
    do
    {
        vec.push_back(str);
    } while (next_permutation(str.begin(), str.end()));
    cout<<vec.size()<<endl;
    for (const auto &item : vec){
        cout<<item<<endl;
    }
}