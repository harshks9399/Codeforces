/*
 Author : Harsh Kumar Singh
 created at : 2024-09-04 21:29:43
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair

const int N = 1e3 + 1;
vector<vector<pair<int,int>>>adj(N, vector<pair<int,int>>());
vector<int>dist(N, INT_MAX/10);

void solve(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(mp(b,c));
        adj[b].push_back(mp(a,c));
    }

    priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
    >pq;
    pq.push(mp(0,1));
    dist[1] = 0;
    bool good = false;
    while(pq.size()!=0){
        auto top = pq.top();
        pq.pop();
        int node= top.second, curr_dist = top.first;
        if(node==n){
            good = true;
            break;
        }
        for(auto it : adj[node]){
            int next = it.first, d = it.second;
            if(dist[next] > curr_dist + d){
                dist[next] = curr_dist + d;
                pq.push(mp(dist[next], next));
            }
        }
    }

    if(!good)cout<<"-1\n";
    else cout<<dist[n]<<"\n";
    return;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}