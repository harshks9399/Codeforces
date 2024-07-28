// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const int MOD = 1e9 + 7;

void solve(){
    int n,x; cin>>n>>x;

    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];

    vector<vector<int>>dp(2, vector<int>(x+1,0));
    dp[0][0]=1;
    for(int i=1;i<=x;i++) 
        if(i-coins[0]>=0) 
            dp[0][i] = dp[0][i-coins[0]];
    
    // for(int it:dp[0])
    //     cout<<it<<" ";
    // cout<<"\n";

    for(int i=1;i<n;i++){
        dp[1] = dp[0];

        for(int j=1;j<=x;j++)
            if(j-coins[i]>=0) 
                dp[1][j] = (dp[1][j] + dp[1][j-coins[i]])%MOD;
    
        dp[0] = dp[1];
    }
    cout<<dp[0][x];
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}