#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
#include <utility>
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;

bool valid(int i, int j, vvi &vis, int n, int m){
    if (!(i<n && i>=0 && j<m && j>=0)){
        return false;
    }
    if (vis[i][j]) return false;
    return true;
}

void dfs(int r, int c, vvi &vis, vector<pair<int, int>> &moves) {
    vis[r][c]=1;
    //cout<<r<<" "<<c<<endl;
    vector<pair<int, int>> next;
    for (int i=0; i<moves.size(); i++) {
        next.push_back(make_pair(r+moves[i].first, c+moves[i].second));
    }
    //cout<<"next moves are ";
    for (int i=0; i<next.size(); i++) {
        if (valid(next[i].first, next[i].second, vis, vis.size(), vis[0].size())){
            //cout<<next[i].first<<" "<<next[i].second<<endl;
        }
    }
    for (int i=0; i<next.size(); i++) {
        int x = next[i].first, y = next[i].second;
        if (valid(x, y, vis, vis.size(), vis[0].size())){
            dfs(x, y, vis, moves);
        }
    }
}

int main(){
    int n, m; cin>>n>>m;
    vvi map; char c;
    map.resize(n, vi(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>c;
            map[i][j] = (c=='#' ? 1 : 0);
        }
    }
    int rooms = 0;
    vector<pair<int, int>> moves = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!map[i][j]){
                dfs(i, j, map, moves);
                rooms+=1;
            }
        }
    }
    cout<<rooms<<endl;
}
