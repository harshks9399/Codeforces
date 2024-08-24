/*
 Author : Harsh Kumar Singh
 created at : 2024-08-24 11:26:31
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
const int N = 1e5 + 1;
// vector<vector<pair<int,int>>>adj(N, vector<pair<int,int>>());
// vector<lli>dist(N,1e11+1);
// vector<int>par(N);
// vector<bool>check(N,false);

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>>adj(n+1, vector<pair<int,int>>());
    vector<int>par(n+1,-1);
    vector<bool>check(n+1,false);
    vector<lli>dist(n+1, 1e11l + 1);

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(mp(b,c));
        adj[b].push_back(mp(a,c));
    }
    priority_queue<pair<lli,int>, vector<pair<lli,int>>, greater<pair<lli,int>>>pq;
    dist[1] = 0;
    pq.push({0,1});
    while(pq.size()!=0){
        auto top = pq.top();
        pq.pop();
        int curr = top.second;
        lli d = top.first;
        if(check[curr]) continue;
        check[curr] = true;
        for(auto it: adj[curr]){
            int node = it.first;
            lli len = it.second;

            if(len + d >= dist[node]) continue;
            dist[node] = len + d;
            par[node] = curr;
            pq.push(mp(dist[node], node));
        }
    }

    if(par[n]==-1){
        cout<<"-1\n";
        return;
    }

    int x = n;
    vector<int>ans;
    ans.push_back(x);
    while(x!=1){
        x = par[x];
        ans.push_back(x);
    }
    reverse(ans.begin(), ans.end());
    for(int it: ans){
        cout<<it<<" ";
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