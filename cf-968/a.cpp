/*
 Author : Harsh Kumar Singh
 created at : 2024-08-25 20:05:50
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<char>v(n);
    for(char &c : v) cin>>c;
    if(v[0]==v[n-1]) cout<<"NO\n";
    else cout<<"YES\n";
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