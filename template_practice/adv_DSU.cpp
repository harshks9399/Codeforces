/*
 Author : Harsh Kumar Singh
 created at : 2024-08-21 19:57:10
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const int N = 1e5;
vector<pair<int,int>>par(N);
vector<int>rank_(N);

void make_set(int x){
    par[x] = make_pair(x,0);
    rank_[x] = 0;
}
pair<int,int> find_par(int x){
    auto v = par[x];
    if(x==v.first) return v;
    int len = v.second;
    par[x] = find_par(par[x].first);  // parent node compression
    par[x].second += len; // length compression, if u dont understand the logic just do a dry run on a -> b
    return par[x];
}

void join(int a, int b){
    auto aa = find_par(a);
    auto bb = find_par(b);
    a = aa.first;
    b = bb.first;
    if(a==b) return;
    if(rank_[a] < rank_[b]) swap(a,b);
    par[b] = make_pair(a,1);
    if(rank_[a]==rank_[b]) rank_[a]++;
}



void solve(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) make_set(i);

    while(m--){
        int a,b;
        cin>>a>>b;
        join(a,b);
    }

    for(int i=1;i<=n;i++){
        cout<<i << " : " << find_par(i).first << " : "<<  find_par(i).second <<"\n";
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}