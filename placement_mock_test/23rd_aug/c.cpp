/*
 Author : Harsh Kumar Singh
 created at : 2024-08-23 21:19:27
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define lli long long int
int N = 2e5+1;
vector<vector<pair<int,int>>> adj(N, vector<pair<int,int>>());

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==b) continue;
        adj[a].push_back(mp(b,c));
        adj[b].push_back(mp(a,c));
    }    

    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}