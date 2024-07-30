// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void dfs(vector<vector<int>>&grid, vector<vector<int>>&check, int x, int y){
    int n = grid.size();
    int m = grid[0].size();
    if(x<0 || x>=n || y<0 || y>=m) return;
    if(check[x][y]==1) return;
    check[x][y] = 1;
    dfs(grid, check, x+1, y);
    dfs(grid, check, x, y-1);
    dfs(grid, check, x, y+1);
    dfs(grid, check, x-1, y);
}


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m)), check(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a;cin>>a;
            if(a=='#') {grid[i][j]=1; check[i][j]=1;}
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!check[i][j]){
                dfs(grid, check, i, j);
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}