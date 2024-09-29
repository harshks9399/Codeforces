/*
 Author : Harsh Kumar Singh
 created at : 2024-09-03 20:12:21
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    lli x,y,k;
    cin>>x>>y>>k;
    if(x%k==0) x = x/k;
    else x = 1 + (x/k);
    if(y%k==0) y = y/k;
    else y = 1 + (y/k);
    if(x > y) cout<<2*x - 1<<"\n";
    else cout<<2*y<<"\n";
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