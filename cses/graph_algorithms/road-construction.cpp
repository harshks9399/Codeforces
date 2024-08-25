/*
 Author : Harsh Kumar Singh
 created at : 2024-08-25 23:52:06
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const int N  =1e5;
vector<int>par(N+1,-1);
vector<int>size(N+1, -1);

void make_set(int x){
    par[x] = x;
    size[x] = 1;
}

int find(int x){
    if(par[x]==x) return x;
    return par[x] = find(par[x]);
}

int join(int x, int y){
    x = find(x);
    y = find(y);

    if(x==y) return size[x];

    if(size[x] < size[y]) swap(x,y);
    par[y] = x;
    size[x] += size[y];
    return size[x];
}

void solve(){
    int maxi = 1;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) make_set(i);
    int com = n;
    while(m--){
        int a,b;
        cin>>a>>b;
        a = find(a);
        b = find(b);
        if(a!=b) com--;
        int s = join(a,b);
        maxi = max(maxi, s);
        cout<<com<<" "<<maxi<<"\n"; 
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}