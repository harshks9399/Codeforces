/*
 Author : Harsh Kumar Singh
 created at : 2024-10-03 17:35:02
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    if(n<=1){
        cout<<n<<"\n";
        return ;
    }
    vector<long long >dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    long long yel= 2, blu = 1;
    for(int i=3;i<=n;i++){
        //dp[i] = dp[i-1];
        // dp[i] = 1;
        // for(int j=i-1;j>=1;j-=2) dp[i] = (dp[i] + dp[j])%mod;
        if(i%2==1) {
            dp[i] = yel + 1;
            blu = (blu+dp[i])%mod;
        }
        else {
            dp[i] = blu + 1;
            yel = (yel + dp[i])%mod;
        }
    }
    long long ans = 0;
    for(int it: dp) cout<<it<<" ";
    cout<<"\n";
    for(auto  it: dp) ans =  (ans + it)%mod;
    cout<<ans<<"\n";
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