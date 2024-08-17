/*
 Author : Harsh Kumar Singh
 created at : 2024-08-17 10:45:58
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const int N = 2e5 + 1;
vector<lli>s1(N,0);
vector<lli>ans(N,0), dist(N,0), child(N,1);
vector<vector<int>>m(N,vector<int>());

void dfs(int index, int par){
    for(int it: m[index]){
        if(it==par) continue;
        dist[it] = 1 + dist[index];
        ans[1] += dist[it];
        dfs(it,index);
        child[index] +=  child[it];
    }
}
void helper(int index, int par,int n){
    for(int it:m[index]){
        if(it==par) continue;
        ans[it] = ans[index] + n - 2*child[it];
        helper(it, index, n);
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    dfs(1,-1);
    helper(1,-1,n);

    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<child[i]<<"\n";
    // }

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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