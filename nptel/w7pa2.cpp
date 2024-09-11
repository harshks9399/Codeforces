/*
 Author : Harsh Kumar Singh
 created at : 2024-09-11 10:03:11
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
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dist(n+1, vector<int>(n+1));
    vector<int>par(n+1);
    vector<int>_rank(n+1);
    for(int i=1;i<=n;i++){
        par[i]= i;
        _rank[i] = 0;
    }
    priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>
    >pq;
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        pq.push(mp(z,mp(x,y)));
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
    cout<<curr<<"\n";
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