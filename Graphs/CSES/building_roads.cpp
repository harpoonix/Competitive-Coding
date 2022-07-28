#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
using namespace std;

void dfs(vvi &graph, vi &vis, int v){
    vis[v]=1;
    for (int i=0; i<graph[v].size(); i++) {
        if (!vis[graph[v][i]]){
            dfs(graph, vis, graph[v][i]);
        }
    }
}

void city(vector<pi> &roads, int n) {
    vvi graph;
    graph.resize(n, vi(0));
    for (int i=0; i<roads.size(); i++) {
        graph[roads[i].first-1].push_back(roads[i].second-1);
        graph[roads[i].second-1].push_back(roads[i].first-1);
    }

    vi vis;
    vis.resize(n, 0);
    vi connection;
    for (int i=0; i<n; i++) {
        if (!vis[i]){
            connection.push_back(i);
            dfs(graph, vis, i);
        }
    }
    cout<<connection.size()-1<<endl;
    if (connection.size()-1){
        for (int i=0; i<connection.size()-1; i++) {
            cout<<connection[i]+1<<" "<<connection[i+1]+1<<endl;
        }
    }
}

int main(){
    int n, m; cin>>n>>m;
    vector<pi> roads;
    roads.resize(m, pi(0,0));
    int a, b;
    for (int i=0; i<m; i++) {
        cin>>a>>b;
        roads[i]=pi(a, b);
    }
    //cout<<"made roads\n";
    city(roads, n);
}
