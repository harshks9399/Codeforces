// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    lli n,m;
    cin>>n>>m;
    lli ans  = 0;

    for(lli i=1;i<=m;i++){
        lli sum = ((n/i) + 1) / i;
        ans += sum;
    }
    ans--;
    cout<<ans<<"\n";
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