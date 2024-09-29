/*
 Author : Harsh Kumar Singh
 created at : 2024-08-26 09:01:01
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
const int N = 2e5 + 1;
vector<int> dsu(N,-1);
vector<int> size(N,-1);
vector<vector<int>>adj(N, vector<int>());
vector<int>par;

void make_set(int x){
    dsu[x] = x;
    size[x] = 1;
}

int find(int x){
    if(x==dsu[x]) return x;
    return dsu[x] = find(dsu[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(size[x] < size[y]) swap(x ,y);
    dsu[y] = x;
    if(size[x]==size[y]) size[x]++;
    return;
}


void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<lli, pair<int,int>>> edges(m);
    for(auto &it : edges) cin>>it.second.first>>it.second.second>>it.first; 
    priority_queue<
        pair<lli, pair<int,int>>,
        vector<pair<lli, pair<int,int>>>,
        greater<pair<lli, pair<int,int>>>
    >pq;
    for(auto it: edges) pq.push(it);
    // cout<<"TAKING IP\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}