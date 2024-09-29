/*
 Author : Harsh Kumar Singh
 created at : 2024-09-04 22:31:40
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair

const int N = 1e5 +1;
vector<int>v;
vector<vector<pair<int,int>>t(4*N, vector<pair<int,int>>());
vector<map<int,int>>tmap(4*N, map<int,int>);



void build(int node, int L , int R){
    if(L==R){
        t[node] = mp(v[L], L); // updating array
        tmap[node][L] = 0; // updating score
    }

    int M = (L+R)/2;
    build(2*node, L, M);
    build(2*node + 1, M+1, R);
    t[node] = t[2*node];
    for(auto it: t[2*node + 1]) t[node].push_back(it);
    



}


void solve(){
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}