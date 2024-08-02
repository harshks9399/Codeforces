// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void bfs(pair<int,int>it , vector<vector<int>>&dist, vector<vector<int>>&grid){
    queue<pair<int,int>>q;
    int n = dist.size(), m = dist[0].size();
    q.push(it);
    dist[it.first][it.second] = 0;
    int row[4] = {1,0,-1,0};
    int col[4] = {0,1,0,-1};
    while(q.size()!=0){
        auto top = q.front();
        q.pop();
        int x = top.first, y = top.second;

        for(int i=0;i<4;i++){
            int r = x+ row[i];
            int c = y+ col[i];

            if(r<0 || c<0 || r>=n  || c>=m) continue;
            if( grid[r][c]==1) continue;
            if(dist[r][c] > dist[x][y] + 1){
                dist[r][c] = dist[x][y] + 1;
                q.push({r,c});
            }
        }
    }
}

void bfs1(int ax, int ay , vector<vector<int>>&dist, vector<vector<int>>&grid, vector<vector<char>>&par){
    queue<pair<int,int>>q;
    int n = dist.size(), m = dist[0].size();
    q.push({ax,ay});
    dist[ax][ay] = 0;
    int row[4] = {1,0,-1,0};
    int col[4] = {0,1,0,-1};
    char dir[4] = {'D', 'R' , 'U' , 'L' };
    while(q.size()!=0){
        auto top = q.front();
        q.pop();
        int x = top.first, y = top.second;

        for(int i=0;i<4;i++){
            int r = x+ row[i];
            int c = y+ col[i];

            if(r<0 || c<0 || r>=n  || c>=m) continue;
            if( grid[r][c]==1) continue;
            if(dist[r][c] > dist[x][y] + 1){
                dist[r][c] = dist[x][y] + 1;
                q.push({r,c});
                par[r][c] = dir[i];
            }
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>>monsters;
    vector<vector<int>>grid(n,vector<int>(m,1e9));
    vector<vector<int>>distm(n,vector<int>(m,1e9));
    vector<vector<int>>dista(n,vector<int>(m,1e9));
    vector<vector<char>>par(n,vector<char>(m));
    int ax,ay;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='M') monsters.push_back({i,j});
            if(c=='A') {ax=i;ay=j;}
            if(c=='#') grid[i][j] = 1;
        }
    }

    for(auto it:monsters){
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        bfs(it, dist, grid);

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                distm[i][j] = min(distm[i][j], dist[i][j]);
            }
    }
    bfs1(ax,ay,dista,grid,par);

    pair<>
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
        solve();
    return 0;
}