/*
 Author : Harsh Kumar Singh
 created at : 2024-08-29 21:06:43
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const int N = 2e5 + 1;
int n;
vector<vector<int>>adj(N , vector<int>());
vector<lli>ans(N);
vector<int>child(N, 0);

lli d1 = 0;

void dfs(int curr, int top, int cd){
    d1 += cd;
    // bool good = false;
    for(int it: adj[curr]){
        if(it == top) continue;
        dfs(it, curr, cd+1);
        // good = true;
        child[curr] += 1 + child[it];
    }
    // if(!good) 
}

void dfs2(int curr, int top){
    

    for(int it: adj[curr]){
        if(it==top) continue;

        ans[it] = ans[curr] + n - 2*(child[it] + 1);
        dfs2(it, curr);
    }
}


void solve(){
    // int n//
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    dfs(1,0, 0);
    ans[1] = d1;
    dfs2(1,0);
    // cout<<d1<<"\n";
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
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