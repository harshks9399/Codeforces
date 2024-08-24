/*
 Author : Harsh Kumar Singh
 created at : 2024-08-24 13:38:36
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair

void dfs(int node, int par, multiset<int>&reachable, vector<vector<int>>&adj){
    if(reachable.find(node) != reachable.end()) return;
    reachable.insert(node);
    for(int it: adj[node]){
        if(it==par) continue;
        dfs(it, node, reachable, adj);
    } 
}


void solve(){
    int n,m;
    cin>>n>>m;
    //vector<vector<pair<lli,int>>>adj_rev(n+1,vector<pair<lli,int>>());
    vector<pair<pair<int,int>, lli>>edge;
    vector<lli>dist(n+1,LLONG_MAX);
    dist[1]=0;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        // adj[a].push_back(mp(c,b));
        edge.push_back(mp(mp(a,b), -c));
    }
    bool last = false;
    multiset<int>temp;
    for(int i=0;i<n;i++){
        last = (i==n-1);
        for(auto e : edge){
            int a = e.first.first, b = e.first.second;
            lli d = e.second;
            if(dist[a]==LLONG_MAX) continue;
            if(dist[b] <= dist[a] + d) continue;
            if(last) {
                temp.insert(b);
            }
            dist[b] = dist[a] + d;
        }
    }
    vector<vector<int>>adj_rev(n+1, vector<int>());
    for(auto it : edge){
        int a = it.first.first , b = it.first.second;
        adj_rev[b].push_back(a);
    }
    multiset<int>reachable;
    bool good  = true;
    dfs(n,-1, reachable, adj_rev);
    for(int it: temp){
        if(reachable.find(it)!= reachable.end()) {
            good = false;
            break;
        }
    }
    if(good) cout<<-1 *dist[n]<<"\n";
    else cout<<"-1\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}