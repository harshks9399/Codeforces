/*
 Author : Harsh Kumar Singh
 created at : 2024-08-17 14:31:46
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const int N = 2e5 + 1;
const int l = log2(N) + 1;
vector<vector<int>>adj(N,vector<int>());
vector<vector<int>>up(N,vector<int>(l+1,-1));
vector<int>tin(N), tout(N);
int T = 0;
bool helper(int x, int y){
    return (tin[x] <= tin[y] && tout[x] >= tout[y]) ;
}
int lca(int a, int b) {
    if(helper(a, b)) return a;
    if(helper(b, a)) return b;
    for(int i = l; i >= 0; i--) {
        if(up[a][i] != -1 && !helper(up[a][i], b)) {
            a = up[a][i];
        }
    }
    return up[a][0];
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
        dfs(it,index);
    }
    tout[index] = T;
    T++;
}

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    // cin>>q;
    dfs(1,-1);

    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<"\n";
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