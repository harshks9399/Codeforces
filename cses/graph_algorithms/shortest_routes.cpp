// THE BASIC SNIPPET
// We have template for fenwick tree
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
 
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>edge(n+1, vector<pair<int,int>>());
    vector<lli>dist(n+1, LLONG_MAX/10);
    dist[1] = 0;
 
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({c,b});
    }
 
    priority_queue<pair<lli,int>, vector<pair<lli,int>>, greater<pair<lli,int>>>pq;
 
    for(auto it: edge[1]){
        pq.push(it);
        dist[it.second] = it.first > dist[it.second] ? dist[it.second] : it.first;
    }
 
    while(pq.size()!=0){
        auto top = pq.top();
        pq.pop();
        int curr = top.second;
        lli curr_dist = top.first;
 
        for(auto it : edge[curr]){
            lli new_dist = it.first + curr_dist;
            int pos = it.second;
            if(dist[pos] > new_dist){
                dist[pos] = new_dist;
                pq.push({new_dist, pos});
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
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