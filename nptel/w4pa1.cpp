/*
 Author : Harsh Kumar Singh
 created at : 2024-08-21 18:37:25
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string)
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void dfs(int &ans, vector<vector<int>>&vis, vector<vector<int>>&v, int x, int y){
    if(x<0 || y<0 || x>=v.size() || y>=v[0].size()) return;
    if(vis[x][y]==1 || v[x][y]==0) return;
    vis[x][y]=1;
    ans ++;
    dfs(ans, vis, v, x-1, y);
    dfs(ans, vis, v, x+1, y);
    dfs(ans, vis, v, x, y+1);
    dfs(ans, vis, v, x, y-1);
}


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n, vector<int>(m)), vis(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==1 || v[i][j]==0) continue;
            int temp= 0 ;
            dfs(temp, vis, v, i, j);
            ans = max(ans, temp);
        }
    }
    cout<<ans<<"\n";
    

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}