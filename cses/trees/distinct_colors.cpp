/*
 Author : Harsh Kumar Singh
 created at : 2024-08-19 09:24:24
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int n;
int N = 2e5  +1;
vector<vector<int>>adj(N,vector<int>());
vector<int>val(N), ans(N);
vector<multiset<int>>check(N, multiset<int>());

void dfs(int idx, int par){
    for(int it: adj[idx]){
        if(it==par) continue;
        dfs(it,idx);
        for(int it1: check[it]){
            if(check[idx].find(it1)==check[idx].end()) check[idx].insert(it1);
        }
        check[it].clear();
    }
    int it1 = val[idx];
    if(check[idx].find(it1)==check[idx].end()) check[idx].insert(it1);
    ans[idx] = check[idx].size();
}


void solve(){
    cin>>n;
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
    dfs(1,-1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}