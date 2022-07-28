// CodeForces 1600J
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

bool valid(int &r, int &c, int n, int m){
    if (!(r>=0 && r<n && c>=0 && c<m)){
        return false;
    }
    return true;
}

void make_graph(vvi &graph, vvi &tiles, int &n, int &m){
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int val = tiles[i][j];
            int walls[4] = {(val>>3)&1, (val>>2)&1, (val>>1)&1, (val)&1};
            for (int k=0; k<4; k++) {
                if (walls[k]==0){
                    // next = 
                    int r, c;
                    switch(k){
                        case 0:
                            r=i-1; c=j; break;
                        case 1:
                            r=i; c=j+1; break;
                        case 2:
                            r=i+1; c=j; break;
                        case 3:
                            r=i; c=j-1; break;
                    }
                    if (valid(r, c, n, m)){
                        graph[m*i+j].push_back(m*r+c);
                    }
                }
            }
        }
    }
}

void dfs(int r, int c, vvi &graph, vvi &vis, int &n, int &m, int &size){
    vis[r][c]=1;
    size++;
    for (int i=0; i<graph[m*r+c].size(); i++) {
        int x = graph[m*r+c][i]/m;
        int y = graph[m*r+c][i]%m;
        if (!vis[x][y]){
            dfs(x, y, graph, vis, n, m, size);
        }
    }
}

void rooms(vvi &tiles, int &n, int &m) {
    vvi graph;
    graph.resize(n*m, vi(0));
    make_graph(graph, tiles, n, m);
    priority_queue<int> sizes;
    vvi vis; vis.resize(n, vi(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!vis[i][j]){
                int size = 0;
                dfs(i, j, graph, vis, n, m, size);
                sizes.push(size);
            }
        }
    }
    while(!sizes.empty()){
        cout<<sizes.top()<<" ";
        sizes.pop();
    }
    cout<<endl;
}

int main(){
    int n, m; cin>>n>>m;
    vvi tiles; tiles.resize(n, vi(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>tiles[i][j];
        }
    }
    rooms(tiles, n, m);
}
