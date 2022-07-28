#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
bool check(int a, int b){
    int temp=a^b;
    for (int i=0; temp>0; i+=1){
        if (temp%2==1){
            if (temp==1){
                return true;
            }
            return false;
        }
        temp = temp >> 1;
    }
    return false;
}

void print_binary(int m, int &size){
    int n=m;
    int max=pow(2, size-1)+1e-3;
    for (int i=max; i>0; i/=2){
        cout<<n/i;
        n=n%i;
    }
    cout<<endl;
}

void gray(vector<int> &vec, vector<int>::const_iterator pointer, int &size){
    int num=*pointer;
    //print_binary(num, size);
    cout<<num<<endl;
    vec.erase(pointer);
    for (int i=0; i<vec.size(); i+=1){
        if (check(num, vec[i])){
            gray(vec, vec.begin()+i, size);
            return;
        }
    }
    cout<<"\nfinal vec\n";
    for (int i=0; i<vec.size(); i+=1){
        cout<<vec[i]<<endl;
        int ans=num^vec[i];
        cout<<num<<"^"<<vec[i]<<" = "<<ans<<endl;
    }
}

int main(){
    int n; cin>>n;
    int size=pow(2, n)+1e-3;
    vector<int> vec;
    for (int i=0; i<size; i+=1){
        vec.push_back(i);
    }
    gray(vec, vec.begin(), n);
}