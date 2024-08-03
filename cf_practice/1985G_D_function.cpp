// THE BASIC SNIPPET
// We have template for fenwick tree
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod = 1e9 + 7;

lli expo(int x, int y){
    // x ^ y;
    lli ans = 1;

    lli xx = x;
    if(x==0) return 0;

    while(y  > 0){
        if((y & 1) == 1) ans = (ans*xx) % mod;
        y = y>>1;
        xx = (xx*xx) % mod;
    }
    return ans;

}

lli power(long long x, long long y, long long p = mod)
{
    long long res = 1;
 
    x = x % p;
    while (y > 0)
    {
 
        if (y & 1)
            res = (res * x) % p;
 
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}



void solve(){
    int l,r,k;
    cin>>l>>r>>k;
    if(k>=10){
        cout<<"0\n";
        return;
    }
    // int m = 1 + (9/k);
    // lli ans  =0;
    // lli c1=1,c2=1;

    // cout<<power(m,r)<<" ";
    // while(r--){
    //     c1 = (c1*m) % mod;
    // }
    // cout<<" "<<c1<<"\n";
    
    // c1 = (c1 + mod -1)%mod;
    // if(l==0){
    //     cout<<c1<<"\n";
    //     return;
    // }
    // // l--;
    // cout<<expo(m,l)<<" ";
    // while(l--){
    //     c2 = (c2*m) % mod;
    // }
    // cout<<" "<<c2<<"\n";

    // c2 = (c2 + mod -1)%mod;
    // ans = (c1-c2+mod)%mod;
    // cout<<ans<<"\n";

    int m = 1 + (9/k);

    // m = (9+k)/k;
    // lli c1 = expo(m,r);
    // c1 = (c1 + mod -1) % mod;

    // lli c2 = expo(m,l);
    // c2 = (c2 + mod -1) % mod;
    // lli ans = (c1-c2 + mod) % mod;
    // if(l==0) ans = c1; 
    lli ans = 1;
    ans = expo(m,r) - expo(m,l);
    // ans = power(m,r) - power(m,l);
    if(ans < 0) ans += mod;

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