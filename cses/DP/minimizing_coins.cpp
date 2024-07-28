// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,k;cin>>n>>k;
    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    if(k==0) {
        cout<<0;
        return;
    }
    sort(coins.begin(), coins.end());
   
    vector<int>dp(k+1, 1e9);
    dp[0]=0;

    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i-coins[j]>=0)
            dp[i] = min(dp[i], dp[i-coins[j]]+1);
        }
    }
    cout<<(dp[k]==1e9 ? -1 : dp[k]);
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}