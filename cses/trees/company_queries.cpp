/*
 Author : Harsh Kumar Singh
 created at : 2024-08-17 14:09:13
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const int N =  2e5 + 1;
const int l = log2(N) + 1;
vector<vector<int>>adj(N,vector<int>());
vector<int>depth(N);
vector<vector<int>>up(N, vector<int>(l+1, -1));

void dfs(int index, int par){
    up[index][0] = par;

    for(int i=1;i<=l;i++){
        if(up[index][i-1]==-1) break;
        up[index][i] = up[up[index][i-1] ][i-1];
    }

    for(int it:adj[index]){
        if(it==par) continue;
        depth[it] = depth[index] + 1;
        dfs(it,index); 
    }
}

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int a;cin>>a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    depth[1] = 0;
    dfs(1,-1);
    while(q--){
        int x,h;
        cin>>x>>h;
        if(h > depth[x]){
            cout<<"-1\n";
            continue;
        }
        if(h == depth[x]){
            cout<<"1\n";
            continue;
        }
        if(h==0){
            cout<<x<<"\n";
            continue;
        }

        int idx = 0;
        int ans = x;
        while(h!=0){
            if((h & 1) == 1) ans = up[ans][idx];
            idx++;
            h = h >> 1;
        }
        cout<<ans<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}