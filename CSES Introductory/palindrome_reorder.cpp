#include <iostream>
#include <string>
using namespace std;

void palindrome(int* alpha, int start, int &odd){
    if (start==26){
        if (odd!=-1){
            char p=65+odd;
            for (int i=0; i<alpha[odd]; i+=1){
                cout<<p;
            }
        }
        return;
    }
    int times=alpha[start];
    if (times==0||times%2==1){
        return palindrome(alpha, start+1, odd);
    }
    
    char p=65+start;
    for (int i=0; i<times/2; i+=1){
        cout<<p;
    }
    palindrome(alpha, start+1, odd);
    for (int i=0; i<times/2; i+=1){
        cout<<p;
    }
}

int main(){
    string list;
    int alphabets[26]; //keeps count of apperance of different alphabets
    for (int i=0; i<26; i+=1){
        alphabets[i]=0;
    }
    getline(cin, list);
    char temp;
    for (auto i=list.begin(); i<list.end(); i+=1){
        temp=*i;
        alphabets[temp-65]+=1;
    }
    int oddcount=0; int oddplace=-1;
    for (int i=0; i<26; i+=1){
        if (alphabets[i]%2==1){
            oddcount+=1;
            oddplace=i;
        }
        if (oddcount>1){
            cout<<"NO SOLUTION";
            return 0;
        }
    }
    palindrome(alphabets, 0, oddplace);
}