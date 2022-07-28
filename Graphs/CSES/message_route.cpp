#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define vp vector<pi>
using namespace std;

void print_path(vi &parent){
    int n = parent.size();
    vi path; path.push_back(n-1);
    int comp = n-1;
    while(comp!=0){
        comp = parent[comp];
        path.push_back(comp);
    }
    reverse(path.begin(), path.end());
    cout<<path.size()<<endl;
    for (int i=0; i<path.size(); i++) {
        cout<<path[i]+1<<" ";
    }
    cout<<endl;
}

void route(vp &conn, int n) {
    vvi graph;
    graph.resize(n, vi(0));
    for (int i=0; i<conn.size(); i++) {
        int a = conn[i].first-1, b=conn[i].second-1;
        graph[a].push_back(b); graph[b].push_back(a);
    }
    //cout<<"reached here\n";
    vi parent; parent.resize(n, -1);
    vi vis; vis.resize(n, 0);
    vis[0]=1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int c = q.front();
        //cout<<c<<endl;
        q.pop();
        for (int i=0; i<graph[c].size(); i++) {
            int node = graph[c][i];
            if (!vis[node]){
                vis[node]=1;
                q.push(node);
                parent[node] = c;
                if (node==n-1){
                    print_path(parent);
                    return;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE\n";

}

int main(){
    int n, m; cin>>n>>m;
    vp connections;
    connections.resize(m, pi(0, 0));
    int a, b;
    for (int i=0; i<m; i++) {
        cin>>a>>b;
        connections[i]=pi(a, b);
    }
    route(connections, n);
}
