/*
 Author : Harsh Kumar Singh
 created at : 2024-08-22 18:29:20
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int N = 1e5 +1;
vector<vector<int>>adj(N, vector<int>());
vector<int>cats(N);
int ans = 0;
int n,m;
void dfs(int idx, int par, int &temp){
    // temp += cats[idx];
    int new_temp = 0;
    if(cats[idx]) new_temp = temp + 1;
    if(new_temp > m){
        return;
    }
    if(adj[idx].size()==1 && adj[idx][0] == par){
        ans++;
        // cout<<"leaf at "<<idx<<"\n";
        return;
    }
    for(int it: adj[idx]){
        if(it==par) continue;
        dfs(it,idx, new_temp);
    }
    // temp -= cats[idx];
}



void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>cats[i];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int temp = 0;
    dfs(1,-1,temp);
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