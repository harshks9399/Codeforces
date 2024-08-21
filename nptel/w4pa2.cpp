/*
 Author : Harsh Kumar Singh
 created at : 2024-08-21 18:49:31
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string)
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void dfs(int node,int par,  multiset<int>&check, vector<vector<int>>&v){
    if(check.find(node)!=check.end()) return ;
    check.insert(node);
    for(int it: v[node]) {
        if(it==par) continue;
        dfs(it, node, check, v);
    }
    return;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>>v(n+1,vector<int>());
    multiset<int>check;
    while(k--){
        int a,b;
        cin>>a>>b;
        if(a==b) continue;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(check.find(i)!=check.end()) continue;
        ans ++;
        dfs(i, -1, check, v);
    }
    cout<<ans<<"\n";
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