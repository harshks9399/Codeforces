/*
 Author : Harsh Kumar Singh
 created at : 2024-08-19 08:09:53
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int n,q;
int N = 2e5 + 1;
vector<vector<int>>adj(N, vector<int>());
vector<int>tin(N), tout(N), val(N);
int T = 0;

void dfs(int idx, int par){
    T++;
    tin[idx] = T;
    for(int it:adj[idx]){
        if(it==par) continue;
        dfs(it,idx);
    }
    tout[idx] = T;
}

void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        val[i] = x;
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    while(q--){
        int type;
        cin>>type;

        if(type==1){
            int node, nval;
            cin>>node>>nval; 
        }else{
            int node;
            cin>>node;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}