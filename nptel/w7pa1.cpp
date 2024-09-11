/*
 Author : Harsh Kumar Singh
 created at : 2024-09-11 09:38:12
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair

int find_par(int x, vector<int>&par){
    if(par[x]==x) return x;
    par[x] = find_par(par[x], par);
    return par[x];
}

void join(int u, int v, vector<int>&par, vector<int>&_rank){
    u = find_par(u, par);
    v = find_par(v, par);
    if(u==v) return;
    if (_rank[u] < _rank[v]) swap(u,v);
    par[v] = u;
    if(_rank[u]==_rank[v]) _rank[u]++;
}


void solve(){
    int n,x;
    cin>>n>>x;
    vector<vector<int>>dist(n, vector<int>(n));
    vector<int>par(n);
    vector<int>_rank(n);
    for(int i=0;i<n;i++){
        par[i]= i;
        _rank[i] = 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int d;
            cin>>d;
            dist[i][j] = d;
        }
    }
    priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>
    >pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) pq.push(mp(dist[i][j], mp(i,j)));
    }
    int curr = 0;
    while(pq.size()!=0){
        auto top = pq.top();
        pq.pop();
        int u = top.second.first, v = top.second.second;
        int d= top.first;
        if(find_par(u,par)==find_par(v,par)) continue;
        join(u,v, par, _rank);
        curr += d;
    }
    cout<<curr*x<<"\n";
    return;
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