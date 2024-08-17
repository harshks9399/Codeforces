/*
 Author : Harsh Kumar Singh
 created at : 2024-08-17 17:35:52
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int N = 2e5 + 1;
int l = log2(N) + 1;
vector<vector<int>>up(N, vector<int>(l+1,-1));
vector<vector<int>>adj(N, vector<int>());
vector<int>tin(N), tout(N), prefix(N), ans(N);
int T = 0;
bool helper(int a,int b){
    return (tin[a] <= tin[b]) && (tout[a] >= tout[b]);
}
int lca(int a,int b){
    if(helper(a,b)) return a;
    if(helper(b,a)) return b;
    for(int i=l;i>=0;i--){
        if(up[a][i]==-1) continue;
        if(!helper(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}
void dfs2(int idx, int par){
    for(int it:adj[idx]){
        if(it==par) continue;
        dfs2(it,idx);
        prefix[idx] += prefix[it];
    }
}
void dfs(int idx, int par){
    tin[idx] = T;
    T++;
    up[idx][0] = par;
    for(int i=1;i<=l;i++){
        if(up[idx][i-1]==-1) break;
        up[idx][i] = up[ up[idx][i-1] ][i-1];
    }
    for(int it:adj[idx]){
        if(it==par) continue;
        dfs(it,idx);
    }
    tout[idx] = T;
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
    dfs(1,-1);
    while(q--){
        int a,b;
        cin>>a>>b;
        prefix[a]++;
        prefix[b]++;
        prefix[lca(a,b)]--;
        if( up[lca(a,b)][0]!=-1  ) prefix[up[lca(a,b)][0]]--;
    }
    dfs2(1,-1);
    for(int i=1;i<=n;i++){
        cout<<prefix[i]<<" ";
    }cout<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}