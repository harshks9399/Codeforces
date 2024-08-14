/*
 Author : Harsh Kumar Singh
 created at : 2024-08-15 00:38:05
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    lli n,k;
    cin>>n>>k;
    vector<lli>v(n);
    for(auto &it : v) cin>>it;

    lli ans = 0;

    lli curr = 0;
    for(lli it: v){
        curr += it;
        if(curr < 0) curr = 0;
        ans = ans > curr ? ans : curr;
    }

    cout<<ans*k<<"\n";
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