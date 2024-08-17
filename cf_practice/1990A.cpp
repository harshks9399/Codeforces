/*
 Author : Harsh Kumar Singh
 created at : 2024-08-17 08:53:57
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    map<int,int>m;
    while(n--){
        int x;cin>>x;
        m[-1*x]++;
    }
    bool good = false;
    for(auto it: m){
        if(it.second % 2 == 1) good = true;
        if(good) break;
    }
    if(good) cout<<"YES\n";
    else cout<<"NO\n";
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