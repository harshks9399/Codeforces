// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void dfs(vector<vector<int>>&v, vector<vector<int>>&check, int n, int x, int y){
    if(x<0 || x>1) return;
    if(y<0 || y>=n) return;
    if(check[x][y]) return;

    check[x][y] = 1;
    dfs(v,check,n,x+1,y);
    dfs(v,check,n,x,y+1);
    dfs(v,check,n,x,y-1);
}


int num_connected(vector<vector<int>>&v){
    int ans = 0;
    int n = v[0].size();
    vector<vector<int>>check = v;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            if(check[i][j])continue;
            ans++;
        }
    }
    return ans;

}

void solve(){
    int n;cin>>n;
    vector<vector<int>>v(2,vector<int>(n));
    int flag_off=1;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            char x;
            cin>>x;
            if(x=='x') v[i][j] = 1;
            else flag_off = 0;
        }
    }
    
    if(flag_off || n<=2){
        cout<<0<<"\n";
        return;
    }


    int ans = 0;
    for(int i=1;i<n-1;i++){
        if(v[0][i] || v[1][i]) continue;
        if(v[0][i-1]==0 && v[0][i+1]==0 && v[1][i-1]==1 && v[1][i+1]==1) ans++;
    }


    for(int i=1;i<n-1;i++){
        if(v[1][i] || v[0][i]) continue;
        if(v[1][i-1]==0 && v[1][i+1]==0 && v[0][i-1]==1 && v[0][i+1]==1) ans++;
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