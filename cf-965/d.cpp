// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,m;
    cin>>n>>m;
    if(m==0){
        n--;
        while(n--) cout<<"1";
        cout<<"\n";
        return;
    }
    map<int,set<int>>edge;
    vector<pair<int,int>>temp;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        // pq.push({x,y});
        temp.push_back({x,y});
        edge[x].insert(y);
    }
    for(int i=1;i<n;i++) edge[i].insert(i+1);

    vector<int>dist(n+1, INT_MAX/2);
    dist[1] = 0;
    for(int it:edge[1]) {pq.push({1, it}); dist[it]=1;}
    while(pq.size()!=0){
        auto top = pq.top();
        pq.pop();
        int loc = top.second, d = top.first;
        for(int it:edge[loc]){
            int nd = d + 1;
            if(dist[it] <= nd) continue;
            dist[it] = nd;
            pq.push({nd, it});
        }
    }

    while(pq.size()!=0) pq.pop();
    for(auto it: temp) pq.push(it);

    // for(int it:dist) cout<<it<<" ";
    // cout<<"\n";


    for(int i=1;i<n;i++){
        if(pq.size()==0){
            cout<<"1";
            continue;
        }
        auto it = pq.top();
        int s = it.first, e = it.second;
        if( i <= s){
            cout<<"1";
            continue;
        }
        if(i >= e){
            pq.pop();
            i--;
            continue;
        }

        int ct = e-i;
        int ht = dist[s] + 1;
        // cout<<i<<" "<<ct<<" "<<ht<<"\n";
        if(ht < ct){
            cout<<"0";
            continue;
        }
        else{
            pq.pop();
            i--;
            continue;
        }
    }
    cout<<"\n";
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