// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod= 1e9 + 7;


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<vector<lli>>dp(n, vector<lli>(m+2));
    if(arr[0]==0){
        for(int i=1;i<=m;i++) dp[0][i]++;
    }else dp[0][arr[0]] = 1;

    for(int i=1;i<n;i++){
        if(arr[i]!=0){
            dp[i][arr[i]] =  (dp[i-1][arr[i]] + dp[i-1][arr[i]+1] + dp[i-1][arr[i]-1])%mod;
            // dp[i][arr[i]] = dp[i-1][arr[i]];
            // if(arr[i]>=2) dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]-1])%mod;
            // if(arr[i]<=m-1) dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]+1])%mod;
            continue;
        }
        for(int j=1;j<=m;j++)
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1])%mod;
    }
    lli ans = 0;
    for(auto it:dp[n-1]){
        ans = (ans + it)%mod;
    }
    // for(auto m:dp){
    //     for(auto it:m) cout<<it.first<<" ";
    //     cout<<"\n";
    // }

    cout<<ans;
    return;


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}