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

bool dfs(int vertex, int col, vvi &graph, vi &vis, vi &color){
    vis[vertex]=1;
    color[vertex]=col;
    for (int i=0; i<graph[vertex].size(); i++) {
        int node =graph[vertex][i];
        if (!color[node]){
            if (!dfs(node, col^3, graph, vis, color)){
                return false;
            }
        }
        if (color[node]==color[vertex]){
            return false;
        }
    }
    return true;
}

bool color_graph(vvi &graph, vi &vis, vi &color){
    for (int i=0; i<graph.size(); i++) {
        if (!vis[i]){
            if (!dfs(i, 1, graph, vis, color)){
                return false;
            }
        }
    }
    return true;
}

void teams(vp &friends, int n) {
    vvi graph;
    graph.resize(n, vi(0));
    for (int i=0; i<friends.size(); i++) {
        int a = friends[i].first-1, b = friends[i].second-1;
        graph[a].push_back(b); graph[b].push_back(a);
    }
    //cout<<"graph made\n";
    vi vis;
    vis.resize(n, 0);
    vi color; color.resize(n, 0);
    if (!color_graph(graph, vis, color)){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    for (int i=0; i<n; i++) {
        cout<<color[i]<<" ";
    }
    cout<<endl;

}

int main(){
    int n, m; cin>>n>>m;
    vp friends; int a, b;
    friends.resize(m, pi(0, 0));
    for (int i=0; i<m; i++) {
        cin>>a>>b;
        friends[i] = pi(a, b);
    }
    //cout<<"initialisation\n";
    teams(friends, n);
}
