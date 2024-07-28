// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const int MOD = 1e9 + 7;


void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    sort(coins.begin(), coins.end());
    vector<int>dp(x+1);
    dp[0] = 1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-coins[j]>=0) dp[i] = (dp[i] + dp[i-coins[j]])%MOD;
        }
    }
    cout<<dp[x];
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}