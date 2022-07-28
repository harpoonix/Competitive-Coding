// CodeForces 1627C
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

bool check(vvi &graph){
    int n = graph.size();
    for (int i=0; i<n; i++) {
        if (graph[i].size()>2){
            return false;
        }
    }
    return true;
}

void dfs(vvi &graph, vi &vis, int node, map<pi, int> &edges, int w){
    vis[node]=1;
    //cout<<"visited "<<node+1<<endl;
    for (int i=0; i<graph[node].size(); i++) {
        int next = graph[node][i];
        if (!vis[next]){
            auto it = edges.find(pi(node, next));
            if (it!=edges.end()){
                edges[pi(node, next)]=w;
                //cout<<"edge "<<node+1<<" "<<next+1<<" has weight "<<w<<endl;
            }
            else {
                edges[pi(next, node)]=w;
                //cout<<"edge "<<next+1<<" "<<node+1<<" has weight "<<w<<endl;
            }

            dfs(graph, vis, next, edges, 2+(w==2));
        }
    }
}

void solve() {
    int n; cin>>n;
    vvi graph;
    map<pi, int> edges;
    vp edge_list; edge_list.resize(n-1);
    // edges.resize(n-1, make_pair(pi(0, 0), 0));
    graph.resize(n, vi(0));
    int a, b;
    for (int i=0; i<n-1; i++) {
        cin>>a>>b;
        //edges[i]=make_pair(pi(a-1, b-1), 0);
        edges.insert(make_pair(pi(a-1, b-1), 0));
        edge_list[i]=pi(a-1, b-1);
        graph[a-1].push_back(b-1); graph[b-1].push_back(a-1);
    }
    if (!check(graph)){
        cout<<-1<<endl;
        return;
    }
    vi vis; vis.resize(n, 0);
    int leaf_node;
    for (int i=0; i<graph.size(); i++) {
        if (graph[i].size()==1){
            leaf_node=i;
            break;
        }
    }
    //cout<<"leaf node "<<leaf_node+1<<endl;
    dfs(graph, vis, leaf_node, edges, 2);
    /*
    for (auto i=edges.begin(); i!=edges.end(); i++) {
        cout<<i->first.first<<" "<<i->first.second<<" weight is "<<i->second<<" \n";
    }*/
    for (int i=0; i<n-1; i++) {
        pi edge = edge_list[i];
        cout<<edges[edge]<<" ";
    }
    cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    for (int i=0; i<t; i++) {
        solve();
    }
}
