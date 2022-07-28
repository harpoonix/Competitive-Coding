#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int chess(int n, int places[8][8]){
    int value=0;
    if (n==8){
        return 1;
    }
    for (int i=0; i<8; i+=1){
        if (places[n][i]==0){
            int bruh[8][8];
            copy(&places[0][0], &places[0][0]+64, &bruh[0][0]);
            for (int j=0; j<8; j+=1){
                bruh[n][j]=1;
                bruh[j][i]=1;
            }
            for (int y=0; y<8; y+=1){
                for (int x=0; x<8; x+=1){
                    if (abs(n-y)==abs(i-x)){
                        bruh[y][x]=1;
                    }
                }
            }
            value+=chess(n+1, bruh);
        }
    }
    return value;
}

int main() {
    int reserved[8][8];
    char t;
    for (int i=0; i<8; i+=1){
        for (int j=0; j<8; j+=1){
            cin>>t;
            if (t=='*'){
                reserved[i][j]=1;
            }
            else reserved[i][j]=0;
        }
    }
    int sum=chess(0, reserved);
    cout<<sum;
}