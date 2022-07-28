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

bool valid(vvi &vis, int r, int c){
    if (!(r<vis.size() && r>=0 && c<vis[0].size() && c>=0)){
        return false;
    }
    return (!vis[r][c]);
}

void print_path(vector<vector<pi>> &path, pi &start, pi &end){
    cout<<"YES\n";
    pi point = end, move; string ans=""; 
    int length = 0;
    while(point!=start){
        move = path[point.first][point.second];
        if (move==pi(1, 0)){
            ans.append("D");
        }
        if (move==pi(-1, 0)){
            ans.append("U");
        }
        if (move==pi(0, 1)){
            ans.append("R");
        }
        if (move==pi(0, -1)){
            ans.append("L");
        }
        point = pi(point.first-move.first, point.second-move.second);
        length+=1;
    }
    reverse(ans.begin(), ans.end());
    cout<<length<<"\n"<<ans<<endl;
}

void path(vvi &vis, pi &start, pi &end) {
    int ax = start.first, ay = start.second, bx = end.first, by = end.second;
    vector<pi> moves = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    vector<vector<pi>> path;
    path.resize(vis.size(), vector<pi>(vis[0].size(), pi(0, 0)));
    queue<pi> q;
    q.push(pi(ax, ay));
    vis[ax][ay]=1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        //cout<<"point is "<<x<<" "<<y<<endl;
        q.pop();
        for (int i=0; i<4; i++) {
            int nx = x+moves[i].first, ny = y+moves[i].second;
            if (valid(vis, nx, ny)){
                q.push(pi(nx, ny));
                vis[nx][ny] = 1;
                path[nx][ny] = {moves[i].first, moves[i].second};
                if (pi(nx, ny)==end){
                    print_path(path, start, end);
                    return;
                }
            }
        }
    }
    cout<<"NO\n";

}

int main(){
    int n, m; cin>>n>>m;
    vvi labyrinth;
    labyrinth.resize(n, vi(m, 0));
    char c; pair<int, int> start, end;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>c;
            if (c=='A') {
                start = make_pair(i, j);
                labyrinth[i][j]=1; continue;
            }
            else if (c=='B'){
                end = make_pair(i, j);
            }
            labyrinth[i][j] = (c=='#' ? 1 : 0);
        }
    }
    //cout<<"labyrinth made\n";
    path(labyrinth, start, end);
}
