/*
 Author : Harsh Kumar Singh
 created at : 2024-08-19 13:23:33
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const lli M = 1e9 + 7;

lli expo(lli a, lli b, lli mod ){
    if(a==0){
        if(b==0) return 1;
        else return 0;
    }
    lli ans = 1;
    while(b!=0){
        if(b&1) ans = (ans * a)%mod;
        a = (a*a ) % mod;
        b = b>>1;
    }
    return ans;
}

void solve(){
    lli a,b,c;
    cin>>a>>b>>c;
    cout<<expo(a,expo(b,c, M-1), M)<<"\n";
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