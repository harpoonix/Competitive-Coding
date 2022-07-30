#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <map>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define vp vector<pi>
using namespace std;

void solve() {
    int n, k; cin>>n>>k;
    vvi graph; graph.resize(n, vi(0));
    // vp edges; edges.resize(n-1, pi(0, 0));
    int a, b;
    for (int i=0; i<n-1; i++) {
        cin>>a>>b;
        // edges[i]=pi(a, b);
        graph[a-1].push_back(b-1); graph[b-1].push_back(a-1);
    }
    int neighbours[n]; int layer[n];
    queue<int> q;
    for (int i=0; i<n; i++) {
        int nei = graph[i].size();
        neighbours[i]=nei;
        if (nei<=1){
            q.push(i);
            layer[i]=1;
        }
    }
    while(!q.empty()){
        int node = q.front();
        neighbours[node]=0;
        q.pop();
        for (int i=0; i<graph[node].size(); i++) {
            int next = graph[node][i];
            if (neighbours[next]>1){
                neighbours[next]-=1;
                if (neighbours[next]==1){
                    q.push(next);
                    layer[next]=layer[node]+1;
                }
            }
        }
    }
    int still_left=0;
    for (int i=0; i<n; i++) {
        if (layer[i]>k){
            still_left++;
        }
    }
    cout<<still_left<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    for (int i=0; i<t; i++) {
        solve();
    }
}
