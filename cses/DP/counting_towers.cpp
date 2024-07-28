// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod = 1e9 + 7;

vector<lli>dp1(1e6+1,-1), dp2(1e6+1,-1);

void solve(){
    int n;
    cin>>n;
    // vector<lli>dp1(n+1), dp2(n+1);

    dp1[1] = 1; // keeping top tiles disconncted    |_| |_|
    dp2[1] = 1; //keeping top tiles connected |_ _|
    if(dp1[n]!=-1){
        cout<< (dp1[n] + dp2[n])%mod <<"\n";
        return;
    }
    for(int i=2;i<=n;i++){
        /*
        options:
            1.Extend both sides
            2.Extend one side
            3.Start over(dont extend any)
        */
        dp1[i] = ((dp1[i-1]) + (2*dp1[i-1]) + (dp1[i-1] + dp2[i-1])) % mod;
        dp2[i] = ((dp2[i-1]) + (0) + (dp2[i-1] + dp1[i-1])) % mod;
    }
    cout<< (dp1[n] + dp2[n])%mod <<"\n";
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