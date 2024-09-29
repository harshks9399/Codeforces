/*
 Author : Harsh Kumar Singh
 created at : 2024-08-22 18:44:55
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int


int n,m,k;
const int N= 2e5 + 1;
vector<vector<int>>adj(N,vector<int>());


void solve(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}