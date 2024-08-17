/*
 Author : Harsh Kumar Singh
 created at : 2024-08-17 15:59:01
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const int N = 2e5 + 1;
const int l = log2(N) + 1;
vector<vector<int>>up(N, vector<int>(l+1,-1));
vector<vector<int>>adj(N, vector<int>());
vector<int>tin(N), tout(N), depth(N);
int T= 0;
bool helper(int a, int b){
    return (tin[a]<=tin[b] && tout[a] >= tout[b]);
}
int lca(int a, int b){
    if(helper(a,b)) return a;
    if(helper(b,a)) return b;
    for(int i=l;i>=0;i--){
        if(up[a][i]==-1) continue;
        if(!helper(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}
int find(int a, int b){
    int c = lca(a,b);
    // cout<<"lca = "<<a<<" "<<b<<" "<<c<<"\n";
    return depth[a] + depth[b] - 2*depth[c];
}

void dfs(int index, int par){
    tin[index] = T;
    T++;
    up[index][0] = par;
    for(int i=1;i<=l;i++){
        if(up[index][i-1]==-1) break;
        up[index][i] = up[ up[index][i-1] ][i-1];
    }
    for(int it: adj[index]){
        if(it==par) continue;
        depth[it] = 1 + depth[index];
        dfs(it,index);
    }
    tout[index] = T;
    T++;
}

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    depth[1] = 0;
    dfs(1,-1);
    while(q--){
        int a,b;
        cin>>a>>b;
        int ans = find(a,b);
        cout<<ans<<"\n";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}