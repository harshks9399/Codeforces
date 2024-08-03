// THE BASIC SNIPPET
// We have template for fenwick tree,
#include <bits/stdc++.h>
using namespace std;
#define lli long long int


lli expo(lli x, lli y, lli mod = 1e9 + 7){
    if(x==0) return 0;
    lli ans = 1;
    while(y > 0){
        if(y&1== 1) ans = (ans*x) % mod;
        y= y>>1;
        x = (x*x) % mod; 
    }
    return ans;
}



void solve(){
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
} 