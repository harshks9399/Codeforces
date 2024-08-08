// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const int mod = 1e9 + 7;

lli expo(lli x, lli y, lli mod = 1e9 + 7){
    if(x==0) return 0;
    lli ans = 1;
    while(y > 0){
        if(y & 1 == 1) ans = (ans * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return ans;
}

void solve(){
    int n, k;
    cin>>n>>k;
    cout<<expo(n,k)<<"\n";
    return ;

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