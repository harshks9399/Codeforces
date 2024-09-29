/*
 Author : Harsh Kumar Singh
 created at : 2024-08-24 11:53:38
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<pair<lli,int>>>adj(n+1, vector<pair<lli, int>>());
    vector<lli>dist(n+1, INT_MAX);
    vector<bool>check(n+1,false);
    vector<int>par(n+1,-1);
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(mp(c,b));
        adj[b].push_back(mp(c,a));
    }

    priority_queue<pair<lli,int> , vector<pair<lli, int>>, greater<pair<lli, int>>>pq;
    pq.push(mp(0,1));
    dist[1] = 0;
    while(pq.size()!=0){
        auto top = pq.top();
        pq.pop();
        int curr= top.second;
        lli d = top.first;
        if(check[curr]) continue;
        check[curr] = true;

        for(auto it: adj[curr]){
            int node = it.second;
            lli len = it.first;
            if(len + d >= dist[node]) continue;
            dist[node] = len + d;
            pq.push(mp(dist[node], node));
            par[node] = curr;
        }
    }

    vector<pair<lli,int>>queries;
    while(q--){
        int a,b;
        cin>>a>>b;
        queries.push_back(mp(b,a));
    }
    sort(queries.begin(), queries.end());
    int ans = 0;
    for(auto it: queries){
        check = vector<bool>(n+1, false);
        int node = it.second;
        lli d =it.first;
        if(dist[node] <= d){
            ans++;
            continue;
        }

        pq.push(it);
        while(pq.size()!=0){
            auto top = pq.top();
            pq.pop();
            int curr = top.second;
            d = top.first;
            if(check[curr]) continue;
            check[curr] = true;
            for(auto it2 : adj[curr]){
                node = it2.second;
                lli len = it2.first;
                if(len + d >= dist[node]) continue;
                dist[node] = len + d;
                pq.push(mp(dist[node], node));
            }
        }
    }
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