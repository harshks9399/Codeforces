/*
 Author : Harsh Kumar Singh
 created at : 2024-08-19 13:18:27
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const lli mod= 1e9 + 7;

lli expo(lli a, lli b){
    lli ans = 1;
    while(b!=0){
        if(b&1) ans = (ans * a)%mod;
        a = (a*a ) % mod;
        b = b>>1;
    }
    return ans;
}

void solve(){
    lli a,b;
    cin>>a>>b;
    cout<<expo(a,b)<<"\n";
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