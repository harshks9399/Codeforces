/*
 Author : Harsh Kumar Singh
 created at : 2024-10-14 17:29:24
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod= 1e9 + 7;

void solve(){
    int n,m;
    cin>>n>>m;
    string h,s;
    cin>>h>>s;

    vector<vector<ll>>dp(n+1,vector<ll>(m+1));
    //dp[0][0] = 1;
    for(int i=0;i<=m;i++){
        dp[0][i] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = dp[i][j-1];
            if(h[i-1]==s[j-1]) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mod;
            }
        }
    }
    cout<<dp[n][m]<<'\n';

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